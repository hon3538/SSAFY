from signal import pause
from gpiozero import AngularServo
from time import sleep

servo=AngularServo(21,min_angle=0,max_angle=90)
while True:
    servo.angle=90
    sleep(1)
    servo.angle=0
    sleep(1)
    
'''
servo jitter ( 서보모터가 떨리는 현상 을 제거하기 위해서는
gpiozero Library 보다는 이를 해결한 pigpio 파이 GPIO) 라이브러리를 쓰는것을 추천한다
라는 경고메세지
->무시


'''