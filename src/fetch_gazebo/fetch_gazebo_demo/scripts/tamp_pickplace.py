#!/usr/bin/env python
import sys
import copy
import os
import actionlib
import rospy
import rospkg
import time
import moveit_commander

from math import sin, cos, pi
from moveit_python import (MoveGroupInterface, PlanningSceneInterface, PickPlaceInterface)
from moveit_python.geometry import rotate_pose_msg_by_euler_angles

from control_msgs.msg import FollowJointTrajectoryAction, FollowJointTrajectoryGoal, GripperCommandAction, GripperCommandGoal
from control_msgs.msg import PointHeadAction, PointHeadGoal
from grasping_msgs.msg import FindGraspableObjectsAction, FindGraspableObjectsGoal

#from geometry_msgs.msg import PoseStamped
from move_base_msgs.msg import MoveBaseAction, MoveBaseGoal
from moveit_msgs.msg import PlaceLocation, MoveItErrorCodes, Grasp
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint

from tf.transformations import quaternion_from_euler
#from tf_conversions.transformations import quaternion_from_euler


from gazebo_msgs.srv import (
    SpawnModel,
    DeleteModel,
)

from geometry_msgs.msg import (
    PoseStamped,
    Pose,
    Point,
    Quaternion,
)


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

            #obj.object.name = find_result.objects[idx].name -> 'GraspableObject' object has no attribute 'name
            obj.object.name = "obj%d"%idx
            self.scene.addSolidPrimitive(obj.object.name, obj.object.primitives[0], obj.object.primitive_poses[0], use_service=False)
            if obj.object.primitive_poses[0].position.x < 1.3: #< 0.85:
                objects.append([obj, obj.object.primitive_poses[0].position.y]) ##should be it's goal position,,,
                #objects.append([obj, obj.object.primitive_poses[0].position.z])

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

        # store graspable objects by Z -> y
        objects.sort(key=lambda object: object[1])
        #objects.reverse()
        self.objects = [object[0] for object in objects]

#obj0_goal = (0, Pose(position=Point(x=1.114, y= -0.858, z= 0.65), orientation=Quaternion(x=0, y=0, z=0, w=1)))

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
                print("!!!!!!!!!!!!!!!A!!!!!!!!!!!!!!!!")
                continue
            print("DIMENSIONS:")
            print(obj.object.primitives[0].dimensions[0])
            print(obj.object.primitives[0].dimensions[1])
            print(obj.object.primitives[0].dimensions[2])

            # has to be on table
            if obj.object.primitive_poses[0].position.z < 0.35:
                print("!!!!!!!!!!!!!!!B!!!!!!!!!!!!!!!!")
                continue
            if obj.object.primitive_poses[0].position.x < 0.3:
                print("!!!!!!!!!!!!!!!C!!!!!!!!!!!!!!!!")
                continue

            # get goal object
            if (( abs(obj.object.primitive_poses[0].position.x - goal_obj_x) > 0.09) and ( abs(obj.object.primitive_poses[0].position.y - goal_obj_y) > 0.09)):
                print("!!!!!!!!!!!!!!!D!!!!!!!!!!!!!!!!")
                continue
            #if ( abs(obj.object.primitive_poses[0].position.y - goal_obj_y) > 0.09):
            #    print("!!!!!!!!!!!!!!!E!!!!!!!!!!!!!!!!")
            #    continue

            print("**************************************Object Name: ", obj.object.name)
            print("Object Pose: ", obj.object.primitive_poses[0])
            print("object primitive: ", obj.object.primitives[0])

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
            l.place_pose.pose = rotate_pose_msg_by_euler_angles(l.place_pose.pose, 0, 0, 2 * pi / m)
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
     rospy.logerr("Spawn SDF service call failed: {0}".format(e))
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
if __name__ == "__main__":
    rospack = rospkg.RosPack()
    pack_path = rospack.get_path('fetch_gazebo')
    rospy.init_node("demo") # Create a node

    # Make sure sim time is working
    while not rospy.Time.now():
        pass

    # Setup clients
    head_action = PointHeadClient()
    grasping_client = GraspingClient() # Control scene, robot, arm
    grasping_client.stow() # Go to a default pose
    cube_in_grapper = False


    # five models: two spam, two apple, one can
    #init_pose = [Pose(position=Point(x=0.797289, y=-0.202685, z=0.7), orientation=Quaternion(*quaternion_from_euler(1.570802, 0, 0.584973))), # spam
    #             Pose(position=Point(x=0.687616, y=0.0000000, z=0.7), orientation=Quaternion(*quaternion_from_euler(1.570802, 0, 0.000000))), # apple
    #             Pose(position=Point(x=0.795236, y=0.0000000, z=0.7), orientation=Quaternion(*quaternion_from_euler(1.570768, 0, 0.000000))), # apple
    #             Pose(position=Point(x=0.725095, y=0.1509680, z=0.7), orientation=Quaternion(*quaternion_from_euler(1.571486, 0, 2.591819))), # spam
    #             Pose(position=Point(x=0.779330, y=0.2442900, z=0.7), orientation=Quaternion(*quaternion_from_euler(1.570780, 0, 2.587536)))] #tomato

    #obj0_goal = (0, Pose(position=Point(x=0.590828, y= -0.267816,  z= 0.65), orientation=Quaternion(*quaternion_from_euler(1.571479, 0, 3.127323))))
    #obj1_goal = (1, Pose(position=Point(x=0.600903, y= 0.062221,   z= 0.65), orientation=Quaternion(*quaternion_from_euler(1.570768, 0, 2.595484))))
    #obj2_goal = (2, Pose(position=Point(x=0.511358, y= -0.032457,  z= 0.65), orientation=Quaternion(*quaternion_from_euler(1.570768, 0, 2.595484))))
    #obj3_goal = (3, Pose(position=Point(x=0.591000, y= -0.166935,  z= 0.65), orientation=Quaternion(*quaternion_from_euler(1.571479, 0, 3.127323))))
    #obj4_goal = (3, Pose(position=Point(x=0.605295, y= 0.079781,   z= 0.65), orientation=Quaternion(*quaternion_from_euler(1.570780, 0, 2.587536))))

    init_pose = [Pose(position=Point(x=0.797289, y=-0.202685, z=0.58), orientation=Quaternion(*quaternion_from_euler(1.570802, 0, 0))), # spam
                Pose(position=Point(x=0.687616, y=0.1000000, z=0.58), orientation=Quaternion(*quaternion_from_euler(1.570802, 0, 0.000000)))] #tomato

    obj0_goal = (0, Pose(position=Point(x=0.590828, y= -0.167816,  z= 0.65), orientation=Quaternion(*quaternion_from_euler(1.571479, 0, 3.127323))))
    obj1_goal = (1, Pose(position=Point(x=0.600903, y= 0.062221,   z= 0.65), orientation=Quaternion(*quaternion_from_euler(1.570768, 0, 2.595484))))



    #obj_goal = [obj0_goal, obj1_goal, obj2_goal, obj3_goal, obj4_goal]
    obj_goal = [obj0_goal, obj1_goal]

    sorted_obj_goal = sorted(obj_goal, key=lambda obj: (obj[1].position.y, -obj[1].position.x))

    object_no = 2
    for b in range(0, object_no): #generate block objects
    #m: 0-spam, 1-apple, 2-apple, 3-spam, 4-tomato
    #mm0: apple, mm1: spam, mm2: spam, mm3: toamto
        object_path = os.path.join(pack_path, 'models', 'block', 'm'+str(11)+'.sdf')
        object_name = 'obj'+str(b)
        object_pose = init_pose[b]
        spawn_gazebo_model(object_path, object_name, object_pose)
        time.sleep(1.0)


    obj_i = -1
    while not rospy.is_shutdown():
        obj_i += 1
        head_action.look_at(1.2, 0.0, 0.0, "base_link")
        print("*******Waiting for lookat 1")
        time.sleep(2.0)

        # Get block to pick
        fail_ct = 0
        while not rospy.is_shutdown() and not cube_in_grapper:
            rospy.loginfo("Picking object...")
            print("*******obj index: ", obj_i)
            grasping_client.updateScene()

            print("*******goal y index: ", sorted_obj_goal[obj_i][0])
            print("*******goal object y: ", init_pose[sorted_obj_goal[obj_i][0]].position.y)

            cube, grasps = grasping_client.getGraspableObject(init_pose[sorted_obj_goal[obj_i][0]].position.x, init_pose[sorted_obj_goal[obj_i][0]].position.y)

            if cube == None:
                rospy.logwarn("Perception failed.")
                # grasping_client.intermediate_stow()
                grasping_client.stow()
                head_action.look_at(1.2, 0.0, 0.0, "base_link")
                continue

            # Pick the block
            if grasping_client.pick(cube, grasps):
                cube_in_grapper = True
                print("Pick Success")
                time.sleep(3.0)
                break

            rospy.logwarn("Grasping failed.")
            grasping_client.stow()
            if fail_ct > 15:
                fail_ct = 0
                break
            fail_ct += 1

        # Place the block
        while not rospy.is_shutdown() and cube_in_grapper:
            rospy.loginfo("Placing object...")
            pose = PoseStamped()
            pose.pose = cube.primitive_poses[0]
            pose.pose.position = sorted_obj_goal[obj_i][1].position
            #pose.pose.orientation = sorted_obj_goal[obj_i][1].orientation   #YS TODO: orientation
            pose.header.frame_id = cube.header.frame_id
            if grasping_client.place(cube, pose):
                cube_in_grapper = False
                time.sleep(1.0)
                grasping_client.stow()
                break
            rospy.logwarn("Placing failed.")
            #grasping_client.intermediate_stow()
            grasping_client.stow()
            if fail_ct > 15:
                fail_ct = 0
                break
            fail_ct += 1
        # Tuck the arm, lower the torso

#        obj_i += 1
        grasping_client.intermediate_stow()
        grasping_client.stow()
        rospy.loginfo("Finished")
        #torso_action.move_to([0.0, ])
