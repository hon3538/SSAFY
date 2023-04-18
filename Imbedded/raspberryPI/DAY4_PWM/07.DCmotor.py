from gpiozero import PWMLED
from time import sleep

motor=PWMLED(3)

while True:
    motor.value=0
    print('speed=0')
    sleep(1)
    motor.value=0.5
    print('speed=0.5')
    sleep(3)
    motor.value=1
    print('speed=1')
    sleep(3)
    motor.value=0.5
    print('sleep=0.5')
    sleep(1)