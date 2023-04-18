from gpiozero import LED
from gpiozero import Button
from signal import pause
from time import sleep

led=LED(2)
but1=Button(27)
but2=Button(17)
led.value=1
# 500hz= 0.002 s

duty=0

def brighter():
    global duty
    if duty+0.1>0.9: duty=0
    else : duty+=0.1
    print(duty)
    
def fadeaway():
    global duty
    if duty-0.1<0:
        duty=0.9
    else : duty-=0.1
    print(duty)
    
but1.when_pressed=brighter
but2.when_pressed=fadeaway

while True:
    led.on()
    sleep(duty*0.002)
    led.off()
    sleep((1-duty)*0.002)
