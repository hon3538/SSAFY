from gpiozero import Button
from gpiozero import LED
from signal import pause
from time import sleep

button =Button(21)
led=(LED(2),LED(3),LED(4),LED(5),LED(6))

index=0

def timing():
    global