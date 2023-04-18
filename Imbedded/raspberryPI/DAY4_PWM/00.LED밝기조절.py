from gpiozero import PWMLED
from time import sleep
led=PWMLED(2)
led.value=0.1
# 입력 값에 따라 밝기 10%씩 변경
while True:
    print(">>",end="")
    a=input()
    if a=='1' and led.value<=0.9:
        print("1")
        led.value+=0.1
    elif a=='0' and led.value>=0.1:
        print("0")