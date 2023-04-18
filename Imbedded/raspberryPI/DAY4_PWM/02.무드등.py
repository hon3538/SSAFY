from gpiozero import PWMLED
from gpiozero import Button
from signal import pause
from time import sleep
G=PWMLED(2)
R=PWMLED(3)
B=PWMLED(4)

R_b=Button(22)
G_b=Button(27)
B_b=Button(17)

red=1
green=1
blue=1
R.value=red
G.value=green
B.value=blue
def Red():
    global red
    red+=0.1
    if red>1 :
        red=0
    R.value=red
    print("red")
    
def Green():
    global green
    green+=0.1
    if green>1 :
        green=0
    G.value=green
    print("green")
def Blue():
    global blue
    blue+=0.1
    if blue>1 :
        blue=0
    B.value=blue
    print("blue")
R_b.when_pressed=Red
G_b.when_pressed=Green
B_b.when_pressed=Blue
pause()

