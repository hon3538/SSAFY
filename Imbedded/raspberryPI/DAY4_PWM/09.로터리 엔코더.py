# 엔코더
# 회전하는 축의 위치를 측정하기 위해 사용되는 기기
# 회전속도 / 방향 / 각도를 측정하는 데 도움을 준다


from signal import pause
from gpiozero import RotaryEncoder, Button

# wrap : 범위 벗어나면 고정 or 해제
# max_steps : 최대값
rotor=RotaryEncoder(16,20,wrap=True, max_steps=180)
# .steps: 시작값
rotor.steps=-180
rot_btn=Button(12)

def change_hue():
    print(rotor.steps)
    
def say_hello():
    print("hello")
    
rotor.when_rotated=change_hue
rot_btn.when_pressed=say_hello
pause()

