from PySide2.QtWidgets import *
from _dial_ import Ui_Form
from PySide2.QtCore import *
from time import sleep
from gpiozero import LED, AngularServo, Button, PWMLED
class MyApp(QWidget, Ui_Form):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.main()
        self.led1 = PWMLED(16)
        self.led2 = PWMLED(20)
        self.off()

        self.btn = Button(2)
        self.btn.when_pressed = self.pressed

    def main(self):
        pass

    def on(self):
        self.led1.value=1
        self.led2.value=1
    def off(self):
        self.led1.value=0
        self.led2.value=0

    def closeEvent(self, e):
        self.led1.close()
        self.led2.close()

    def _dial(self, val):
        #val = 0~100 --> 0~1
        self.led1.value = val/100
        self.led2.value = (100-val)/100
        self.lb.display(val)

    def pressed(self):
        print("#")
        num=self.led1.value*100
        self.setDial(100-num)



app = QApplication()
win = MyApp()
win.show()
app.exec_()
