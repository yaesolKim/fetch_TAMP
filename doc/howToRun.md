실행 순서
======================

### 1. tufts 패키지 이용하는 경우: 간단하게 joint position 지정해서 pick and place 한다.

1. 가재보 환경 런치
* `roslaunch fetch_tufts pickplace_playground.launch`

2. 데모 프로그램 런치
* `roslaunch fetch_tufts pick_and_place_tufts.launch num_of_run:=1`



### 2. 기본 fetch_gazebo 이용하는 경우: moveit 쓰는 경우로, 아직 구현중

1. 가재보 환경 런치
* `roslaunch fetch_gazebo pickplace_playground.launch`

2. 데모 프로그램 런치
* `roslaunch fetch_gazebo_demo pick_place_demo.launch`
