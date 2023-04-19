# LED 가 64개 있는데 MCU가 직접 제어하면 pin이 64개 필요함
# pin 도 부족하지만 너무 낭비..
# Driver의 등장
# MCU는 Driver만 제어하고 Driver는 LED에게 명령을 내린다
# 즉, Driver는 모듈을 제어할 수 있는 Interface 역할을 한다

from sense_hat import SenseHat
from time import sleep

sense=SenseHat()

# 화면 돌리기
sense.show_message("A")
sense.set_rotation(90)
sense.show_message("A")
sense.set_rotation(180)
sense.show_message("A")
sense.set_rotation(270)

# 특정 픽셀에 컬러쓰기
# set_pixel(x,y,pixel)
red=(255,0,0)
sense.set_pixel(0,2,red)

# 전체 픽셀 표기
X =[255,0,0] #Red
O =[0,0,0] #White

question_mark=[
    O,O,X,X,O,X,X,O,
    O,X,O,O,X,O,O,X,
    O,X,O,O,O,O,O,X,
    O,O,X,O,O,O,X,O,
    O,O,O,X,O,X,O,O,
    O,O,O,O,X,O,O,O,
    O,O,O,O,O,O,O,O,
    O,O,O,O,O,O,O,O
    ]
sense.set_pixels(question_mark)

# 반전하기
sense.flip_h() 
sense.flip_v()

# 전체화면 모두 한 컬러로 지정하기
clear(R,G,B)
clear() # 화면 모두 끄기

# 빛의 세기 조절
sense.low_light=True
sleep(2)
sense.low_light=False
#-> 몇몇 디스플레이의 low_light API가 존재한다
# 해당 LED 전압값을 낮춰서 밝기를 낮추는 건지
# rgb값을 이용해서 낮추는 건지 확인 -> 밝기만 낮추려했는데 원하는 색상이 안 나올 수 있음
# ex) 255,0,0 -> 127,0,0

# Show Message 컬러 / 속도 조절
# default speed=0.1 
sense.show_message("1",0.15,text_colour=[255,0,0])
