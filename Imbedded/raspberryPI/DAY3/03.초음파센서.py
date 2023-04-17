#동작방식
#trig / echo 핀
# trig 핀에 high 신호를 준다
# delay() 살짝 끊어서 low 신호를 바꾼다
# target에 튕겨 수신기로 초음파 인식(걸리는 시간 계산하여 거리를 알아낸다)

#초음파 vs 적외선 센서
#초음파는 파동이기 때문에 넓은 범위(레이더)
#적외선은 빛이기 때문에 직진성(카운팅)

from gpiozero import DistanceSensor
from time import sleep

sensor = DistanceSensor(21,20) #Echo, trig
#21,20은 SPI 핀이지만, DistanceSensor는 gpio함수 이므로 그냥 gpio로 동작한다

while True:
    print(sensor.distance,"m")
    sleep(0.1)

'''
사람 지나갈 때마다 count
from gpiozero import DistanceSensor
from time import sleep

sensor = DistanceSensor(21,20) #Echo, trig
count=0
flag=0
while True:
    if flag==0 and sensor.distance<0.8:
        count+=1
        flag=1
        
    if flag==1 and sensor.distance>=1:
        flag=0
    print(sensor.distance,"m")
    sleep(0.1)


'''