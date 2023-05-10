from PySide6.QtWidgets import *
from _pro import Ui_Form
from PySide6.QtCore import *
from time import sleep

class MyThread(QThread):
    mySignal = Signal(int, int)
    stopped = False

    def __init__(self):
        super().__init__()

    def run(self):
        for x in range(101):
            while stop==1:
                sleep(0.01)
            for i in range(5):
                self.mySignal.emit(i, x)
                sleep(0.01)
stop=1
class MyApp(QWidget, Ui_Form):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.th = MyThread()
        #self.th.mySignal.connect(self.settingUI)
        self.th.mySignal.connect(self.setValue)
        #self.th.start()
        self.main()

    def settingUI(self, val):
        print("Get Signal : " + str(val))

    def setValue(self, i, x):
        self.pros[i].setValue(x)

    def main(self):
        self.pros = []
        lay = self.verticalLayout
        for i in range(lay.count()):
            self.pros.append(lay.itemAt(i).widget())
            self.pros[i].setValue(0)
        self.th.start()
    def go(self):
        global stop
        stop=0
    def stop(self):
        global stop
        stop=1

app = QApplication()
win = MyApp()
win.show()
app.exec()