from gpiozero import PWMLED
from time import sleep
G=PWMLED(2)
R=PWMLED(3)
B=PWMLED(4)
while True:
    for i in range(10):
        R.value=(i/10)*0.5
        G.value=((1-i/10))*0.2
        B.value=i/10
        sleep(0.1)