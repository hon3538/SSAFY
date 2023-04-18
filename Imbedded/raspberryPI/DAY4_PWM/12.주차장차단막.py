from gpiozero import AngularServo, LED, Button
from time import sleep

def up():
    global servo, led1, led2
    servo.angle = 0
    led1.on()
    sleep(1)
    led1.off()

def down():
    global servo, led1, led2
    servo.angle = 90
    led2.on()
    sleep(1)
    led2.off()

servo = AngularServo(3, min_angle=0, max_angle=90)
servo.angle=90

btn1 = Button(14)
btn2 = Button(15)
led1 = LED(2)
led2 = LED(4)

btn1.when_pressed = up
btn2.when_pressed = down
