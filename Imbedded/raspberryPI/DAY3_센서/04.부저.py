from gpiozero import TonalBuzzer
from gpiozero.tones import Tone
from time import sleep

lst=[242.32,352.34,810.2]
#220~880Hz
#주파수에 따른 소리 발생
b=TonalBuzzer(17)

while True:
    for i in range(3):
        b.play(lst[i])
        sleep(0.2)
    b.stop()
    break