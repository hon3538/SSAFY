# RFID
# 라디오 주파수를 인식하고 이용하여 통신
# 하이패스, 놀이동산 출입 등에 사용됨
# 취약점, 라디오 주파수만 알면되므로 보안에 취약함

#https://github.com/pimylifeup/MFRC522-python
# git clone 해서 설치 파일들 가져오고 setup.py 설치
# sudo python3 setup.py install
from mfrc522 import SimpleMFRC522
from time import sleep

while True:
    print("Hold a tag near the reader")
    id=SimpleMFRC522().read()[0]
    print(id)
    sleep(0.3)