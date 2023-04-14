from gpiozero import Button
from gpiozero import LED
from signal import pause
from time import sleep

but = Button(21) 
led=(LED(2),LED(3),LED(4),LED(5),LED(6))

index=0
mode=1
def timing():
    global index # 전역변수 사용
    if index==2:
         mode=not mode
but.when_pressed = timing # 스위치 인터럽트

while True:
    #led 순서대로 켰다가 역순으로 끄기
    if mode==1:
        for i in range(5):
            index=i
            led[index].on()
            sleep(0.5)
        for i in range(5):
            index=4-i
            led[index].off()
            sleep(0.5)
    #led 전체 켰다가 전체 끄기
    if mode==0:
        for i in range(5):
             led[i].on()
        sleep(0.5)
        for i in range(5):
             led[i].off()


 
    



