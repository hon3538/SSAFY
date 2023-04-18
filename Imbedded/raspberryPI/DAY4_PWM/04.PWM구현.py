# 같은 듀티비라도 주파수 속도가 다르다
# 너무 낮다면 눈에 깜빡깜빡임이 보인다
# 주파수가 빠르다면 좋다. 하지만 MCY가 빠른속도를 낼 수 있는 한계가 있다

# 주파수는 1초에 몇 번 진동하는지를 의미하며, 1/T (1/sec = Hz) 이다

from gpiozero import LED
from time import sleep
led=LED(2)

# 듀티 80%, 100hz 주파수 
while True:
    led.on()
    sleep(0.008)
    led.off()
    sleep(0.002)