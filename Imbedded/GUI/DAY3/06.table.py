from PySide6.QtWidgets import *
from _table_ import Ui_Form
from PySide6.QtCore import *
from time import sleep
from gpiozero import LED, AngularServo, Button, PWMLED

class MyApp(QWidget, Ui_Form):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.main()

    def main(self):
        t= self.tableWidget
        print(t.rowCount())
        for y in range(t.rowCount()):
            for x in range(t.columnCount()):
                data=t.item(y,x)
                if data:
                    print(data.text())
                else:
                    print("s")
                    t.setItem(y,x,QTableWidgetItem("HI"))

app = QApplication()
win = MyApp()
win.show()
app.exec()