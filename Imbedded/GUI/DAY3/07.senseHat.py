from PySide6.QtWidgets import *
from _senseHat_ import Ui_Form
from sense_emu import SenseHat
from time import sleep
from gpiozero import LED, AngularServo, Button, PWMLED

class MyApp(QWidget, Ui_Form):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.main()

    def main(self):
        self.sense = SenseHat()

    def showText(self):
        txt=self.lineEdit.text()
        self.sense.show_message(txt)
        for y in range(8):
            for x in range(8):
                self.sense.set_pixel(x,y,255,255,255)
                sleep(0.1)
        self.sense.clear()

app = QApplication()
win = MyApp()
win.show()
app.exec()