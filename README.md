# fetch_TAMP

Task and motion planning packages for fetch robot picking and placing objects		


### 1. Clone this repository

`git clone https://github.com/yaesolKim/fetch_TAMP.git`   

### 2. Install packages

If needed.

### 3. Build two catkin workspaces

#### 1. fetch_ws 
```
$ cd fetch_TAMP/fetch_ws
$ catkin build
```

#### 2. dope_ws
```
$ cd fetch_TAMP/dope_ws
$ catkin_make
```

### 4. Run
#### fetch simulation
terminal 1: `$ roslaunch fetch_gazebo tamp_playground.launch`   
terminal 2: `$ roslaunch fetch_gazebo_demo tamp_pickplace.launch`

#### Dope
terminal 3: `$ roslaunch dope dope.launch`   
