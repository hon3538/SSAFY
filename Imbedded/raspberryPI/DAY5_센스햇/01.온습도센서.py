from sense_hat import SenseHat
from time import sleep

sense=SenseHat()

while True:
    humi = sense.get_humidity()
    temp = sense.get_temperature()
    
    print("Humidity : %s" % humi)
    print("Temperature : %s" % temp)
    sleep(1)