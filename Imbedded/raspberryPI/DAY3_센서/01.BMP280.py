from smbus import SMBus
from bmp280 import BMP280 # library 다운로드
from time import sleep

#initialize BMP280
bus = SMBus(1)
bmp280=BMP(i2c_dev=bus)

'''
while True:
    a=bus.read_byte_data(DEVICE_ADDR,0xFA)
    b=bus.read_byte_data(DEVICE_ADDR,0xFB)
    c=bus.read_byte_data(DEVICE_ADDR,0xFC)
    print(a,b,c)
    result=(a<<12)|(b<<4)|((c&0xF0)>>4)
    print(result)
    sleep(0.5)
    # 모듈의 datasheet를 보고 data를 받아온다
    # result값은 그냥 data 값이 되고 이 값을 유의미한 온도나 압력값으로
    # 변환시키려면 수식이 필요하다 -> bmp280 라이브러리에 구현해놨으니 사용하기
    
'''

while True:
    temperature=bmp280.get_temperature()
    pressure=bmp280.get_pressure()
    print('{:05.2f}*C {:05.2f}hPa'.format(temperature,pressure))
    
