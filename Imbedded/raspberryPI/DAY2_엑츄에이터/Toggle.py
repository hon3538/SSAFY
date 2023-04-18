from gpiozero import Button
from gpiozero import LED
from signal import pause
from time import sleep

but = Button(17) 
yel=LED(27)
green=LED(22)
flag=1
def toggle():
    global flag
    if flag==1:
        yel.on()
        green.off()
        flag=0
        print("yellow on")
    else :
        green.on()
        yel.off()
        flag=1
        print("green on")
but.when_pressed = toggle
pause()