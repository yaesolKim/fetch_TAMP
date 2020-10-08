Starting Fetch with ROS indigo
======================

## 0. Manual & Support

Manual: https://docs.fetchrobotics.com/    
Support: http://support.fetchrobotics.com:8080/    
(username: jkim, password: ewhaglab)    


## 1. Install Ubuntu 14.04 LTS (to remote PC)

Making bootable USB: http://webnautes.tistory.com/1146    
Partition: http://blog.dalli.kr/archives/1414    
Remove ubuntu:  http://jimnong.tistory.com/677?category=575588   


## 2. Install ROS Indigo (to remote PC)

Install Ubuntu: http://wiki.ros.org/indigo/Installation/Ubuntu    
Creating catkin workspace: http://wiki.ros.org/ROS/Tutorials/InstallingandConfiguringROSEnvironment    


## 3. Download Fetch packages (to remote PC)

Enter commands below sequentially on remote PC   

```
$ sudo apt-get install ros-melodic-fetch-*    
$ cd ~/catkin_ws    
$ catkin_make
```


## 4. Gazebo Simulation (Without Robot)

Set ROS_MASTER_URI and ROS_HOSTNAME as localhost and run launch file   
Must use while robot power is off


### Network Configuration

Enter ‘$sudo gedit ~/.bashrc’ on terminal   
Add those to the file and save the changes   

```
export ROS_MASTER_URI=http://localhost:11311   
export ROS_HOSTNAME=localhost
```

`$ source ~/.bashrc`


## 5. Moveit (c++)

Commands for launching moveit setup assistant

```
$sudo apt-get install ros-melodic-moveit (sudo apt-get install ros-kinetic-moveit )   
$source /opt/ros/melodic/setup.bash (source /opt/ros/indigo/setup.bash)   
$roslaunch moveit_setup_assistant setup_assistant.launch   
```




Video tutorial for setup assistant GUI

https://www.youtube.com/watch?v=rfcXZcKZd8A&index=4&t=160s&list=LLVR1lsSDfFCKRlT5Rxl21sA



※ This setup assistant process is already done in Fetch robot, so you don’t need this if you’re manipulating robot via terminal. This process is needed when you use gazebo simulator in your remote PC. 

### Generating packages

Create planning group and Generate moveit package   

```
$ git clone -b 0.3-devel https://github.com/ros/cmake_modules.git   
$ catkin_make 
```


create new package for planning   
```
$ cd ~/catkin_ws/src   
$ catkin_create_pkg <pkg_name> <dependency>
```

## 6. Network Configuration 

### In remote PC

Firstly, connect both PC and Fetch to the same Wi-Fi Network   

Enter ‘$sudo gedit /etc/hosts’ on terminal   
Add those to the file and save the changes    
  
``` 
127.0.0.1	localhost   
127.0.1.1	glab-M15x	# PC’s hostname   
192.168.0.56	fetch58         # fetch’s IP address   
```

Enter ‘$sudo gedit ~/.bashrc’ on terminal   
Add those to the file and save the changes   

```
export ROS_HOSTNAME=10.200.23.219         #PC’s IP address   
export ROS_MASTER_URI=http://fetch58:11311   
export LC_ALL=C   
```

Enter ‘$source ~/.bashrc’ on terminal (Necessary)    


### In Fetch PC


Enter ‘$sudo gedit /etc/hosts’ on terminal   
Add those to the file and save the changes   

```
127.0.0.1            localhost   
127.0.1.1            glab-M15x    # PC’s IP address   
10.200.23.219        fetch58   
```


No need to indicate ROS_HOSTNAME and ROS_MASTER_URI in bashrc file in Fetch    


### Test NW configuration

Enter ‘$ping fetch58’ in remote PC   
If you can receive packets as picture above, it’s successfully connected    

## 7. Terminal

Enter terminal   
$ssh fetch@fetch58   

  
All the map files, cpp files, and launch files are recommended to stored at robot PC.   

## 8. Test Teleoperation
```
$rosrun teleop_twist_keyboard teleop_twist_keyboard.py   
```

## 9. Robot Calibration

### Arm

```
$ calibrate_robot --reset   
$ calibrate_robot --arm --install
```   
※ While calibration, message ‘[ERROR]: Found empty JointState message’  can appear even the calibration worked successfully.   
※ Raise the torso to full extension and make free space near robot.

### Torso
```
$ sudo service robot stop   
$ rosrun fetch_drivers torso_calibrate calibrate   
$ rosrun fetch_drivers torso_calibrate verify   
$ sudo service robot start (after calibration completed)   
```
※ Move torso to lower position, and tuck the arm before running calibration. It’d be better to keep holding the robot arm while calibration. 


## 10. Map building

terminal 1: `$ roslaunch fetch_navigation build_map.launch`   
terminal 2: `$ rviz`   
terminal 3: `$ rosrun teleop_twist_keyboard teleop_twist_keyboard.py`   

Move robots and when the map is enough, locate robot to its starting point.   

After building,   

terminal 4: `$ rosrun map_server map_saver -f map_name`    

Kill terminal 1, 2, 3, 4    
move map_name.pgm, map_name.yaml file to /opt/ros/indigo/share/fetch_maps/maps     


## 11. Navigation

`$ roslaunch fetch_navigation fetch_nav.launch map_file:=/opt/ros/indigo/share/fetch_maps/maps/map_name.yaml`



