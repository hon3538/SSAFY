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
        self.tm.setInterval(100)
        self.tm.timeout.connect(self.run)
        # self.tm.start()

    def go(self):
        self.tm.start()
    def run(self):
        self.pb.setValue(self.pb.value()+1)
        if self.pb.value()==100:
            self.tm.stop()

    def pause(self):
        self.tm.stop()

    def reset(self):
        self.pb.setValue(0)

app =QApplication()
win=MyApp()

win.show()
app.exec()