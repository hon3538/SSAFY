from sense_hat import SenseHat
from time import sleep

sense=SenseHat()
# pitch /roll / yaw 로 기울기를 나타낸다
while True:
    ori = sense.get_orientation_degrees()
    print(f'[{ori["pitch"]:5.1f}] - ',end='')
    print(f'[{ori["roll"]:5.1f}] - ',end='')
    print(f'[{ori["yaw"]:5.1f}] - ',end='')
    print()