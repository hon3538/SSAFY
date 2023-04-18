from signal import pause
from gpiozero import RotaryEncoder,Button, PWMLED

rotor = RotaryEncoder(16, 20, wrap=True, max_steps=180)
rot_btn = Button(12)
rotor.steps = -180
rled = PWMLED(14)
gled = PWMLED(15)
yled = PWMLED(18)

def change_hue():
    value = rotor.steps
    if value<=-60: #-180~-60
        rled.value = (value+180)/120 #0~120 0~1
        gled.value =0
        yled.value =0
    elif value<=60: #-60~60
        rled.value =0
        gled.value =(value+60)/120 #0~120 0~1
        yled.value =0
    else : #60~180
        rled.value =0
        gled.value =0
        yled.value =(value-60)/120 #0~120 0~1
    print(value)

def off():
    rled.value=0
    gled.value=0
    yled.value=0

rotor.when_rotated = change_hue
rot_btn.when_pressed = off
pause()
