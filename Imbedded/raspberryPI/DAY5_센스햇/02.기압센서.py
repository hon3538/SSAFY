from sense_hat import SenseHat
from time import sleep

sense=SenseHat()

while True:
    humi = sense.get_humidity()
    temp = sense.get_temperature()
    press= sense.get_pressure()
    
    print("Humidity : %s" % humi)
    print("Temperature : %s" % temp)
    print("Pressure : %s" % press)
    sleep(1)