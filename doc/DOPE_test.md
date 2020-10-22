DOPE(Deep Object Pose Estimation) 테스트해야한다.
======================

우리 환경은 Ubuntu 18.04 + ROS Melodic 이다!

### 1. DOPE 패키지 설치

```
cd ~/catkin_ws/src   
git clone https://github.com/yehengchen/DOPE-ROS-D435.git   
cd ~/catkin_ws/src/DOPE-ROS-D435/dope   
pip install -r requirements.txt   
만약 pip 없는 경우 pip install한다.

cd ~/catkin_ws   
rosdep install --from-paths src -i --rosdistro melodic   
sudo apt-get install ros-melodic-rosbash ros-melodic-ros-comm   
```

### 2. 웨이트값 다운로드하여 넣기

dope/weights에   

### 3. jsk-perception 패키지 인스톨

*소스 받아 빌드하려 했는데 빌드에러남.   

`sudo apt-get install ros-melodic-jsk-perception`

### 4. jsk_perception 패키지에서 sample_image_publisher.launch 파일: 퍼블리셔
roscd jsk_perception에서 cp sample_image_publisher.launch default_sample~~~.launch 로 복사해놓고
sample_image_publisher.launch를 시연이가 준걸로 수정   

시연이가 준 sample_image_publisher.launch에 보면 
file_name: ~~~/kiva_pod_image_color.png 가 있는데 이 사진을 시연이가 준 사진으로 또 바꾼다.
-> file_name: ~~~/000000.jpg
이걸로 이미지 퍼블리쉬하는거다~

### 5. dope/config/config_pose.yaml 파일에서

필요한 내용 넣어주고 알비즈에서 dope 인스트럭션대로 해당 토픽 퍼블리시 확인

### 6. RUN

```
$ cd fetch_tamp
$ roslaunch fetch_tamp pickplace_playground.launch
$ roslaunch fetch_tamp pick_place.launch
```
```
$ cd ~/dope_ws
$ source devel/setup.bash
$ roslaunch dope dope.launch
```

