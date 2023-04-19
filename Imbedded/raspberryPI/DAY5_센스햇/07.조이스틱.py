from sense_hat import SenseHat
from time import sleep

sense=SenseHat()
# 인터럽트 방식
# 키가 눌릴때까지 기다림
while True:
    event=sense.stick.wait_for_event()
    print("The joystick was{} {}".format(event.action, event.direction))
    sleep(0.1)
    
    
'''
폴링 방식의 키 입력 확인 방법
계속 누르면 계속 뜸 (반복문으로 입력을 계속 인지함)
from sense_hat import SenseHat
from time import sleep

sense=SenseHat()

while True:
    for event in sense.stick.get_events():
        print("The joystick was {} {}".format(event.action, event.direction))
'''

'''
누를때마다 좌표바꾸기
from sense_hat import SenseHat, ACTION_PRESSED, ACTION_RELEASED
from signal import pause


from time import sleep


def pushed_up(event):
    global y
    if event.action !=ACTION_RELEASED:
        if y-1<0 : y=0
        else :y -= 1
            
def pushed_down(event):
    global y
    if event.action !=ACTION_RELEASED:
        if y+1>7 : y=7
        else :y += 1
        
def pushed_left(event):
    global x
    if event.action !=ACTION_RELEASED:
        if x-1<0 : x=0
        else :x -= 1
    
def pushed_right(event):
    global x
 
 
 
 if event.action !=ACTION_RELEASED:
        if x+1>7 : x=7
        else :x += 1
    
def refresh():
    sense.clear()
    sense.set_pixel(x,y,255,255,255)
    
x=3
y=3
sense = SenseHat()

sense.stick.direction_up = pushed_up
sense.stick.direction_down = pushed_down
sense.stick.direction_left = pushed_left
sense.stick.direction_right = pushed_right
sense.stick.direction_any = refresh

pause()

'''