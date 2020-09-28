0911_처음 받은 가재보 씬
======================

오브젝트 ue4에서 텍스쳐랑 메쉬 파일 익스포트했다고 했다.
미완이지만 보내준다고 했는데 어느부분이 미완인지는 씬을 열어봐야 하겠다.

일단 월드랑 모델 파일이고, 수정은 안된거라 약간 physical 하지 않고 모델들도 몇가지 설정이 더 추가되어야 하기 때문에 임시용이라고 한다.

아래 링크의 엑셀에 모델 사이즈,무게가 있으니 필요하면 참고하라고 한다.
https://iewha-my.sharepoint.com/:x:/g/personal/syunni33_i_ewha_ac_kr/ET0CipGQRM1Ls4KoYcmEzO8Bm2nKM3ZuNeL_sd1knD2jyQ?e=pvn5k1



-----------------------------------------------------

world 파일이 아닌 sdf 파일만 있다. 이걸 어떻게 열지?
일단 pickplace_playground.launch 파일을 열어서 씬을 어떻게 가져오는지 확인하자.

test/worlds/test.sdf 파일을 fetch_tufts/worlds/sy_test 로 복붙했다.
test/models 아래 모든 폴더들을 fetch_tufts/models 아래로 복붙했다.

fetch_tufts/launch/pickplace_playground.launch 에서 원래의 가재보 월드 로드 명령을 아래처럼 변경했다.
원래: <arg name="world_name" value="$(find fetch_tufts)/worlds/test_zone_pick_place.sdf"/>
변경: <arg name="world_name" value="$(find fetch_tufts)/worlds/sy_test.sdf"/>

sdf 모델들을 못찾는다. fetch_tufts/modesl에 있던 파일은 읽으니 그 파일이 다른데 있지 않은지 확인해봐야겠다.
여러개 나오는데 먼저
1. ./home/glab/.gazebo/models/cafe_table
여기였다. 여기다가 test/models 아래 모든 폴더들을 복붙한다.

그러고나니 가재보 씬이 잘 돌아간다. 이제 pick and place가 되는지 테스트하자.
pick_place.launch 파일에 보면 pick_place.py 스크립트에서 한다는걸 알 수 있다. 파이썬 코드를 보아야한다.

이전에는 내가 임의로 블럭을 생성하고 그걸 잡게 했는데, 지금은 씬에 있는걸 잡을 수 있도록 파이썬 코드를 수정해야 한다.
-> 안된다. 가재보에 있는 오브젝트는 sdf인데 잘 잡히는 내가 만들었던 블럭은 urdf이다. 이 둘의 차이는 뭔가? -> 아니다 그냥 코드로 sdf 파일 가져올 수 있게 만들어버리던지 하자.
그리고 워닝메세지에 쿼터니언이 없다는데 그것부터 확인하자. (잡히는 urdf에는 있고 안잡히는 sdf에는 없을 수도 있다)
