from PySide6.QtWidgets import *
from PySide6.QtUiTools import *
from _form import Ui_Form
from PySide6.QtCore import *
import random
class MyApp(QWidget,Ui_Form):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.main()

    def main(self):
        self.timer = QBasicTimer()
        self.timer.start(400,self)
    def timerEvent(self,e):
        x=random.randint(0,self.frame.size().width() - self.label.width())
        y=random.randint(0,self.frame.size().height()-self.label.height())
        self.label.move(x,y)
    def changeColor(self):
        color = QColorDialog.getColor()
        if color.isValid() :
            self.label.setStyleSheet("background-color:%s" %color.name())
    def changeName(self):
        name, ok = QInputDialog.getText(self,'이름입력','너의 이름은?')
        if ok :
            self.label.setText(name)
            self.label.adjustSize()  # 자동 사이즈 조절

    def showDiagram(self):
        sender = self.sender()
        if sender.text()=="이름변경":
            self.changeName()
        else:
            self.changeColor()
    def mousePressEvent(self,e):
        global cnt
        cnt+=1
        x=e.x()
        y=e.y()
        # self.label.move(x,y)
        tx =self.label.x()
        ty=self.label.y()
        self.lcd.display(cnt)
        if tx <= x <= tx + self.label.width():
            if ty <= y <= ty + self.label.height():
                msg = QMessageBox()
                msg.setText("성공")
                cnt=0
                msg.exec()
                self.lcd.display(cnt)


cnt=0
app = QApplication()
win =MyApp()

win.show()
app.exec()