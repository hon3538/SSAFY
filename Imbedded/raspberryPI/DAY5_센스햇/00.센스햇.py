# 센스햇
# 센서들이 모여있는 Hat
# 자이로 센서, 가속도 센서, 기압 센서, 지자기 센서, 온/습도 센서
# 컨트롤러와 Display (8x8 LED, 8방향 조이스틱)

# 설치방법
# sudo apt get update
# sudo apt get install python sense emu python3 sense emu sense emu tools

from sense_emu import SenseHat

sense = SenseHat()
sense.show_message("HELLO")