import smbus
from time import sleep
DEVICE_BUS =1
DEVICE_ADDR =0x76 #I2C address, i2cdetect -y 1 로 알 수 있다
bus =smbus.SMBus(DEVICE_BUS)

while True:
    # 장치의 Address 주소에서 0x00 레지스터의 값을 읽어온다.
    a=bus.read_byte_data(DEVICE_ADDR,0x00)
    
    print(a)
    sleep(0.5)
