# 가속도 센서
# X, Y, Z 축의 가속도를 측정할 수 있다
# 가속도를 적분해서 속도를 알아낼 수 있다
# 속도를 적분해서 이동 경로를 알아 낼 수 있다

# 가속도 센서를 이용해서 알아 낼 수 있는 정보
# 이동경로, 진동여부(장비 고장여부 판단), 기울기 정도(이건 자이로 센서로도 판단가능함)

from sense_hat import SenseHat
from time import sleep

sense=SenseHat()

# 가속도 출력하기
while True:
    acc = sense.get_accelerometer_raw()
    print(f'[{acc["x"]:5.1f}] - ',end='')
    print(f'[{acc["y"]:5.1f}] - ',end='')
    print(f'[{acc["z"]:5.1f}]',end='')
    print()
    
# 자기력 측정하여 나침반 역할하기
while True:
    com=sense.get_compass_raw()
    print(f'[{com["x"]:5.1f}] - ',end='')
    print(f'[{com["y"]:5.1f}] - ',end='')
    print(f'[{com["z"]:5.1f}]',end='')
    print()