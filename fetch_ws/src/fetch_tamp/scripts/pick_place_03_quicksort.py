#!/usr/bin/env python
import sys
import copy
import os
import actionlib # for using the executetrajectoryaction client
import rospy
import rospkg
import time
import moveit_commander
import geometry_msgs

from math import sin, cos, pi
from moveit_python import (MoveGroupInterface, PlanningSceneInterface, PickPlaceInterface)
from moveit_python.geometry import rotate_pose_msg_by_euler_angles

from control_msgs.msg import FollowJointTrajectoryAction, FollowJointTrajectoryGoal, GripperCommandAction, GripperCommandGoal
from control_msgs.msg import PointHeadAction, PointHeadGoal
from grasping_msgs.msg import Object,FindGraspableObjectsAction, FindGraspableObjectsGoal
#FindGraspableObjectsGoal: bool plan_grasp
from geometry_msgs.msg import PoseStamped, Pose, Point, Quaternion
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal
from moveit_msgs.msg import PlaceLocation, MoveItErrorCodes, Grasp
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint

from gazebo_msgs.srv import (
    SpawnModel,
    DeleteModel,
)

import roslib
from gazebo_msgs.msg import ModelStates
from std_msgs.msg import Float32MultiArray
from geometry_msgs.msg import Twist
from gazebo_msgs.srv import GetModelState



#===================================================================================
# Move base using navigation stack
class MoveBaseClient(object):

    def __init__(self):
        self.client = actionlib.SimpleActionClient("move_base", MoveBaseAction)
        rospy.loginfo("Waiting for move_base...")
        self.client.wait_for_server()
        rospy.loginfo("Waiting for move_base..?.")

    def goto(self, x, y, theta, frame="world"):
        move_goal = MoveBaseGoal()
        move_goal.target_pose.pose.position.x = x
        move_goal.target_pose.pose.position.y = y
        move_goal.target_pose.pose.orientation.z = sin(theta/2.0)
        move_goal.target_pose.pose.orientation.w = cos(theta/2.0)
        move_goal.target_pose.header.frame_id = frame
        move_goal.target_pose.header.stamp = rospy.Time.now()

        # TODO wait for things to work
        self.client.send_goal(move_goal)
        self.client.wait_for_result()

#===================================================================================
# Send a trajectory to controller
class FollowTrajectoryClient(object):

    def __init__(self, name, joint_names):
        self.client = actionlib.SimpleActionClient("%s/follow_joint_trajectory" % name,
                                                   FollowJointTrajectoryAction)
        rospy.loginfo("Waiting for %s..." % name)
        self.client.wait_for_server()
        self.joint_names = joint_names

    def move_to(self, positions, duration=5.0):
        if len(self.joint_names) != len(positions):
            print("Invalid trajectory position")
            return False
        trajectory = JointTrajectory()
        trajectory.joint_names = self.joint_names
        trajectory.points.append(JointTrajectoryPoint())
        trajectory.points[0].positions = positions
        trajectory.points[0].velocities = [0.0 for _ in positions]
        trajectory.points[0].accelerations = [0.0 for _ in positions]
        trajectory.points[0].time_from_start = rospy.Duration(duration)
        follow_goal = FollowJointTrajectoryGoal()
        follow_goal.trajectory = trajectory

        self.client.send_goal(follow_goal)
        self.client.wait_for_result()

#===================================================================================
# Point the head using controller
class PointHeadClient(object):

    def __init__(self):
        self.client = actionlib.SimpleActionClient("head_controller/point_head", PointHeadAction)
        rospy.loginfo("Waiting for head_controller...")
        self.client.wait_for_server()

    def look_at(self, x, y, z, frame, duration=1.0):
        goal = PointHeadGoal()
        goal.target.header.stamp = rospy.Time.now()
        goal.target.header.frame_id = frame
        goal.target.point.x = x
        goal.target.point.y = y
        goal.target.point.z = z
        goal.min_duration = rospy.Duration(duration)
        self.client.send_goal(goal)
        self.client.wait_for_result()

#===================================================================================
def quickSort(x):
    if len(x) <= 1:
        return x

    left,right,equal =[],[],[]
    pivot = x[0]

    for a in x:
        if a[1].position.y < pivot[1].position.y:
            left.append(a)
        elif a[1].position.y > pivot[1].position.y:
            right.append(a)
        else: #equal -> check x value
            #equal.append(a)
            if a[1].position.x > pivot[1].position.x:
                left.append(a)
            else:
                equal.append(a)

    return quickSort(left) + equal + quickSort(right)

#===================================================================================
# Tools for grasping
class GraspingClient(object):

    def __init__(self):
        self.scene = PlanningSceneInterface("base_link")
        self.pickplace = PickPlaceInterface("arm", "gripper", verbose=True)
        self.move_group = MoveGroupInterface("arm", "base_link")

        find_topic = "basic_grasping_perception/find_objects"
        rospy.loginfo("Waiting for %s..." % find_topic)
        self.find_client = actionlib.SimpleActionClient(find_topic, FindGraspableObjectsAction)
        self.find_client.wait_for_server()

    def updateScene(self):
        # find objects
        goal = FindGraspableObjectsGoal()
        goal.plan_grasps = True
        self.find_client.send_goal(goal)
        self.find_client.wait_for_result(rospy.Duration(5.0))
        find_result = self.find_client.get_result()

        rospy.loginfo("Found %d objects" % len(find_result.objects))

        # remove previous objects
        #for name in self.scene.getKnownCollisionObjects():
        #    self.scene.removeCollisionObject(name, False)
        #for name in self.scene.getKnownAttachedObjects():
        #    self.scene.removeAttachedObject(name, False)
        self.scene.waitForSync()

        # insert objects to scene
        objects = list()
        idx = -1
        for obj in find_result.objects:
            idx += 1
            obj.object.name = "obj%d"%idx
            self.scene.addSolidPrimitive(obj.object.name, obj.object.primitives[0], obj.object.primitive_poses[0], use_service=False)
            if obj.object.primitive_poses[0].position.x < 1.3: #< 0.85:
                objects.append([obj, obj.object.primitive_poses[0].position.y])

        #for obj in find_result.support_surfaces:
        #    # extend surface to floor, and make wider since we have narrow field of view
        #    height = obj.primitive_poses[0].position.z
        #    obj.primitives[0].dimensions = [obj.primitives[0].dimensions[0], 1.5,  # wider
        #                                    obj.primitives[0].dimensions[2] + height]
        #    obj.primitive_poses[0].position.z += -height/2.0

        #    # add to scene
        #    self.scene.addSolidPrimitive(obj.name, obj.primitives[0], obj.primitive_poses[0])
        self.scene.waitForSync()

        # store for grasping
        self.surfaces = find_result.support_surfaces

        # store graspable objects by y
        objects.sort(key=lambda object: object[1])
        #objects.reverse()
        self.objects = [object[0] for object in objects]

    def getGraspableObject(self, goal_obj_x, goal_obj_y):
        graspable = None
        for obj in self.objects:
            # need grasps
            if len(obj.grasps) < 1:
                continue
            # check size
            if obj.object.primitives[0].dimensions[0] < 0.03 or \
               obj.object.primitives[0].dimensions[0] > 0.25 or \
               obj.object.primitives[0].dimensions[0] < 0.03 or \
               obj.object.primitives[0].dimensions[0] > 0.25 or \
               obj.object.primitives[0].dimensions[0] < 0.03 or \
               obj.object.primitives[0].dimensions[0] > 0.25:
                continue
            # has to be on table
            if obj.object.primitive_poses[0].position.z < 0.4:
                continue
            if obj.object.primitive_poses[0].position.x < 0.3:
                continue
            # get goal object
            if ( abs(obj.object.primitive_poses[0].position.x - goal_obj_x) > 0.03):
                continue
            if ( abs(obj.object.primitive_poses[0].position.y - goal_obj_y) > 0.03):
                continue
            print("**************************************Object Name: ", obj.object.name)
            print("Object Pose: ", obj.object.primitive_poses[0], obj.object.primitives[0])

            return obj.object, obj.grasps
        # nothing detected
        return None, None

    def getSupportSurface(self, name):
        for surface in self.support_surfaces:
            if surface.name == name:
                return surface
        return None

    def getPlaceLocation(self):
        pass

    def pick(self, block, grasps):
        success, pick_result = self.pickplace.pick_with_retry(block.name, grasps, support_name=block.support_surface, scene=self.scene)
        self.pick_result = pick_result
        #hold the object
        #touch_links = ['l_gripper_finger_link', 'r_gripper_finger_link']
        #self.hand_group.attach_object('apple', 'base_link', touch_links=touch_links)
        return success

    def place(self, block, pose_stamped):
        places = list()
        l = PlaceLocation()
        l.place_pose.pose = pose_stamped.pose
        l.place_pose.header.frame_id = pose_stamped.header.frame_id

        # copy the posture, approach and retreat from the grasp used
        l.post_place_posture = self.pick_result.grasp.pre_grasp_posture
        l.pre_place_approach = self.pick_result.grasp.pre_grasp_approach
        l.post_place_retreat = self.pick_result.grasp.post_grasp_retreat
        places.append(copy.deepcopy(l))
        # create another several places, rotate each by 360/m degrees in yaw direction
        m = 16 # number of possible place poses
        pi = 3.141592653589
        for i in range(0, m-1):
            #l.place_pose.pose = rotate_pose_msg_by_euler_angles(l.place_pose.pose, 0, 0, 2 * pi / m)
            places.append(copy.deepcopy(l))

        success, place_result = self.pickplace.place_with_retry(block.name, places, scene=self.scene)
        return success

    def tuck(self):
        joints = ["shoulder_pan_joint", "shoulder_lift_joint", "upperarm_roll_joint",
                  "elbow_flex_joint", "forearm_roll_joint", "wrist_flex_joint", "wrist_roll_joint"]
        pose = [1.32, 1.40, -0.2, 1.72, 0.0, 1.66, 0.0]
        while not rospy.is_shutdown():
            result = self.move_group.moveToJointPosition(joints, pose, 0.02)
            if result.error_code.val == MoveItErrorCodes.SUCCESS:
                return

    def stow(self):
        joints = ["shoulder_pan_joint", "shoulder_lift_joint", "upperarm_roll_joint",
                  "elbow_flex_joint", "forearm_roll_joint", "wrist_flex_joint", "wrist_roll_joint"]
        pose = [1.32, 0.7, 0.0, -2.0, 0.0, -0.57, 0.0]
        #pose = [-1.60, -1.10, -1.20, -1.50, 0.0, -1.51, 0.0]
        while not rospy.is_shutdown():
            result = self.move_group.moveToJointPosition(joints, pose, 0.02)
            if result.error_code.val == MoveItErrorCodes.SUCCESS:
                return

    def intermediate_stow(self):
        joints = ["shoulder_pan_joint", "shoulder_lift_joint", "upperarm_roll_joint",
                  "elbow_flex_joint", "forearm_roll_joint", "wrist_flex_joint", "wrist_roll_joint"]
        pose = [0.7, -0.3, 0.0, -0.3, 0.0, -0.57, 0.0]
        while not rospy.is_shutdown():
            result = self.move_group.moveToJointPosition(joints, pose, 0.02)
            if result.error_code.val == MoveItErrorCodes.SUCCESS:
                return

#===================================================================================
def spawn_gazebo_model(model_path, model_name, model_pose, reference_frame="world"):
  model_xml = ''
  with open(model_path, "r") as model_file:
    model_xml = model_file.read().replace('\n', '')
  rospy.wait_for_service('/gazebo/spawn_sdf_model')
  try:
    spawn_sdf = rospy.ServiceProxy('/gazebo/spawn_sdf_model', SpawnModel)
    resp_sdf = spawn_sdf(model_name, model_xml, "/", model_pose, reference_frame)
  except rospy.ServiceException, e:
    rospy.logerr("Spawn URDF service call failed: {0}".format(e))

#===================================================================================
def delete_gazebo_model(models):
  """
  Delete model in gazebo
  """
  try:
    delete_model = rospy.ServiceProxy('/gazebo/delete_model', DeleteModel)
    for a_model in models:
      resp_delete = delete_model(a_model)
  except rospy.ServiceException, e:
    rospy.loginfo("Delete Model service call failed: {0}".format(e))


#===================================================================================
#================================================================================
if __name__ == "__main__":
    rospack = rospkg.RosPack()
    pack_path = rospack.get_path('fetch_tamp')
    #moveit_commander.roscpp_initialize(sys.argv)

    rospy.init_node("demo") # Create a node

    # Make sure sim time is working
    while not rospy.Time.now():
        pass

    #sys.setrecursionlimit(10**6)

    # Setup clients
    #move_base = MoveBaseClient()
    head_action = PointHeadClient()
    grasping_client = GraspingClient()

    #grasping_client.stow() # Go to a default pose

    grasping_client.stow() # Go to a default pose
    cube_in_grapper = False

    #move_base.goto(0, 0.2, 0.0)

    # object goal info tuble: (index, Pose)
    obj01_goal = (0, Pose(position=Point(x=1.114, y= -0.858, z= 0.5), orientation=Quaternion(x=0, y=0, z=0, w=1)))
    obj02_goal = (1, Pose(position=Point(x=0.62,  y= -0.793, z= 0.5), orientation=Quaternion(x=0, y=0, z=0, w=1)))
    obj03_goal = (2, Pose(position=Point(x=1.114, y= -0.598, z= 0.5),  orientation=Quaternion(x=0, y=0, z=0, w=1)))
    obj04_goal = (3, Pose(position=Point(x=1.01,  y= 0.182,  z= 0.5), orientation=Quaternion(x=0, y=0, z=0, w=1)))
    obj05_goal = (4, Pose(position=Point(x=1.01,  y= 0.377,  z= 0.5), orientation=Quaternion(x=0, y=0, z=0, w=1)))
    obj06_goal = (5, Pose(position=Point(x=1.01,  y= 0.572,  z= 0.5), orientation=Quaternion(x=0, y=0, z=0, w=1)))
    obj07_goal = (6, Pose(position=Point(x=1.01,  y= 0.702,  z= 0.5), orientation=Quaternion(x=0, y=0, z=0, w=1)))

    obj_goal = [obj01_goal, obj02_goal, obj03_goal, obj04_goal, obj05_goal, obj06_goal, obj07_goal]

    sorted_obj_goal = quickSort(obj_goal)
    #print(quickSort(obj_goal))
    #print(sorted_obj_goal[0][1].position.y)
    print("************************************** Sort the object goal **************************************")
    time.sleep(1.0)

    # Current state of objects
    g_get_state = rospy.ServiceProxy("/gazebo/get_model_state", GetModelState)
    rospy.wait_for_service("/gazebo/get_model_state")
#
#    obj01 = Object
#    #obj01 = g_get_state(model_name="apple")
#    obj01.name = 'apple'
#
#
#    # insert objects to scene
#    obj = list()
#
#    obj01.name = 'apple'
#    scene.addSolidPrimitive(obj01.name, obj01.primitives[0], obj01.primitive_poses[0])
#    obj.append([obj01, obj01.primitive_poses[0].position.z])
#    obj01.
#
#for obj in find_result.objects:
#    idx += 1
#    obj.object.name = "object%d"%idx
#    self.scene.addSolidPrimitive(obj.object.name, obj.object.primitives[0], obj.object.primitive_poses[0])
#    if obj.object.primitive_poses[0].position.x < 0.85:
#        objects.append([obj, obj.object.primitive_poses[0].position.z])
#
#for obj in find_result.support_surfaces:
#    # extend surface to floor, and make wider since we have narrow field of view
#    height = obj.primitive_poses[0].position.z
#    obj.primitives[0].dimensions = [obj.primitives[0].dimensions[0], 1.5,  # wider
#                                    obj.primitives[0].dimensions[2] + height]
#    obj.primitive_poses[0].position.z += -height/2.0
#
#    # add to scene
#    self.scene.addSolidPrimitive(obj.name, obj.primitives[0], obj.primitive_poses[0])
#self.scene.waitForSync()
#
## store for grasping
#self.surfaces = find_result.support_surfaces
#
## store graspable objects by Z
#objects.sort(key=lambda object: object[1])
#objects.reverse()
#self.objects = [object[0] for object in objects]
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#
#    obj02 = g_get_state(model_name="cracker")
#    obj02.name = 'cracker'
#    obj03 = g_get_state(model_name="mustard")
#    obj03.name = 'mustard'
#    obj04 = g_get_state(model_name="spam1")
#    obj05 = g_get_state(model_name="spam2")
#    obj06 = g_get_state(model_name="tomato1")
#    obj07 = g_get_state(model_name="tomato2")
#    obj = [obj01, obj02, obj03, obj04, obj05, obj06, obj07]
#
#    obj_no = 7
#
#    #print(obj02.pose.position.y)

    goal_is_clean = True
    #while not rospy.is_shutdown() and not goal_is_clean: #push the object near goal position to the goal position of object itself
    #    #check the rightmmm
    #    min(obj01.pose.position.y, obj02.pose.position.y, obj03.pose.position.y, obj04.pose.position.y, obj05.pose.position.y, obj06.pose.position.y, obj07.pose.position.y)
    #    print("************************************** Select the object pushed **************************************")
    #    goal_is_clean = True

    i = 0
    #while sorted_obj_goal:
    #    print("************************************** iteration", i, "**************************************")
    #    #while not rospy.is_shutdown() and goal_is_clean: #pick the object
    #    #cube, grasps = grasping_client.getGraspableObject()
    #    obj_index = sorted_obj_goal[0][0] #select the object to pick
    #    print("object index: ", obj_index)
    #    #pick the obj[obj_index]
    #    #grasps = find_result.objects[the_object].grasps
    #    cube, grasps = grasping_client.getGraspableObject()
    #    grasping_client.pick(obj[obj_index], True)

    #    #place the obj[obj_index] to sorted_obj_goal[0][1]
    #    time.sleep(3.0)

    #    #remove the placed object from goal list
    #    sorted_obj_goal.remove(sorted_obj_goal[0])
    #    print(sorted_obj_goal)
    #    i = i+1


    while not rospy.is_shutdown():
        # Get block to pick
        fail_ct = 0
        while not rospy.is_shutdown() and not cube_in_grapper:
            rospy.loginfo("Picking object...")
            grasping_client.updateScene()
            cube, grasps = grasping_client.getGraspableObject()
            #print("############################################cube: " , cube)
            #frame_id: "base_link"

            if cube == None:
                rospy.logwarn("Perception failed.")
                # grasping_client.intermediate_stow()
                grasping_client.stow()
                #head_action.look_at(obj01.pose.position.x, obj01.pose.position.y, obj01.pose.position.z,"base_link")
                head_action.look_at(1.2, 0.0, 0.0, "base_link")
                continue

            # Pick the block
            # pick_with_retry: http://docs.ros.org/jade/api/moveit_python/html/pick__place__interface_8py_source.html
            if grasping_client.pick(cube, grasps):
                cube_in_grapper = True
                break
            print("Pick Success")
            rospy.logwarn("Grasping failed.")
            grasping_client.stow()
            if fail_ct > 15:
                fail_ct = 0
                break
            fail_ct += 1

        # Tuck the arm
        #grasping_client.tuck()

        # Place the block
        while not rospy.is_shutdown() and cube_in_grapper:
            rospy.loginfo("Placing object...")
            pose = PoseStamped()
            pose.pose = cube.primitive_poses[0]
            #pose.pose.position.x += 0.10
            ##pose.pose.position.y = -1.0
            #pose.pose.position.z += 0.02
            pose.pose.position = sorted_obj_goal[0][1].position
            #pose.pose.position.x = 0.6
            #pose.pose.position.y = 0.182#-0.793
            #pose.pose.position.z = 0.65
            pose.header.frame_id = cube.header.frame_id
            if grasping_client.place(cube, pose):
                cube_in_grapper = False
                break
            rospy.logwarn("Placing failed.")
            grasping_client.intermediate_stow()
            grasping_client.stow()
            if fail_ct > 15:
                fail_ct = 0
                break
            fail_ct += 1
        # Tuck the arm, lower the torso
        grasping_client.intermediate_stow()
        grasping_client.stow()
        rospy.loginfo("Finished")
        #torso_action.move_to([0.0, ])
