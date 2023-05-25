from Raspi_MotorHAT import Raspi_MotorHAT, Raspi_DCMotor
from Raspi_PWM_Servo_Driver import PWM
from time import sleep

mh = Raspi_MotorHAT(addr=0x6f) 
myMotor = mh.getMotor(2) #핀번호

servo = PWM(0x6F)
servo.setPWMFreq(60)  # Set frequency to 60 Hz

# Bluetooth
from bluetooth import *
MAC = "8C:CE:4E:9A:38:CA"

def getSpeed(x):
    if 1840 <= x <= 1880:
        speed = 0
        direction = Raspi_MotorHAT.RELEASE
    elif x < 1840:
        speed = 1840 - x * 150 / 1840
        direction = Raspi_MotorHAT.BACKWARD
    else:
        speed = (x - 1880) * 50 / (4095 - 1880)
        direction = Raspi_MotorHAT.FORWARD

    return speed, direction   

def getAngle(y):
    if 1890 <= y <= 1930:
        angle = 340
    elif y < 1890:
        angle = y * 150 / 1890 + 190
    else:
        angle = (y - 1930) * 100 / (4095 - 1930) + 340

    return angle


def main():
    socket = BluetoothSocket(RFCOMM)
    socket.connect((MAC, 1))
    print("bluetooth connected!")

    try:
        while True:
            try:
                data = socket.recv(1024).decode('utf-8')
                x, y, b = map(int, data.split())
                #print("x:", x)
                #print("y:", y)
                #print("b:", b)

                speed, direction = getSpeed(x)
                angle = getAngle(y)

                #print("speed:", speed)
                #print("direction:", direction)
                #print("angle:", angle)
                #print()

                myMotor.setSpeed(int(speed))
                myMotor.run(int(direction))
                servo.setPWM(0, 0, int(angle))
            except KeyboardInterrupt:
                break

            except:
                continue

    finally:
        socket.close()
        myMotor.run(Raspi_MotorHAT.RELEASE)


if __name__ == '__main__':
   main() 
