# fetch_TAMP

Task and motion planning package for fetch robot picking and placing objects		
+ DOPE

### 1. Create catkin workspace

### 2. Install packages
- fetch_gazebo   
- fetch_ros   
- gazebo_pkgs   
- general_message_pkgs   
- moveit_tutorial   
- occupancy_grid_utils   

### 3.Build the catkin workspace
```
$ cd fetch_TAMP
$ catkin build
```

### 4. Run
terminal 1: `roslaunch fetch_tamp pickplace_playground.launch`   
terminal 2: `roslaunch fetch_tamp pick_place.launch`

