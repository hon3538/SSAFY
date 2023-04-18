from gpiozero import PWMLED, Button
from time import sleep

def click():
    print("OH")

VRX =PWMLED(14)
VRY=PWMLED(15)
SW =Button(18)
SW.when_pressed=click
while True:
    dx=VRX.value
    dy=VRY.value
    print(str(dx)+","+str(dy))
    sleep(0.2)
