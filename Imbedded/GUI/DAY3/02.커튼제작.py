from PySide6.QtWidgets import *
from PySide6.QtCore import *
from _pro import Ui_Form

class MyApp(QWidget, Ui_Form):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.main()

    def main(self):
        self.pb.setValue(0)
        self.tm=QTimer()
        self.tm.setInterval(300)
        self.tm.timeout.connect(self.run)
        # self.tm.start()

    def up(self):
        global dir
        dir=-1
        self.tm.start()

    def down(self):
        global dir
        dir=1
        self.tm.start()
    def motor(self):
        print("d")
        self.tm.setInterval(1000-self.ms.value()*10)
    def run(self):
        global dir
        self.pb.setValue(self.pb.value()+dir)
        if self.pb.value()==100 or self.pb.value()==0:
            self.tm.stop()
    def stop(self):
        self.tm.stop()

    def reset(self):
        self.pb.setValue(0)
dir=1
speed=300
app =QApplication()
win=MyApp()

win.show()
app.exec()