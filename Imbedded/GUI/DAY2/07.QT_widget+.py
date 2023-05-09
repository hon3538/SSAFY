from PySide6.QtWidgets import *
from PySide6.QtUiTools import *
from test import Ui_MainWindow
from _design import Ui_Form
class MyApp(QWidget, Ui_Form):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.main()

    def main(self):
        pass
    
    def lover(self):
        self.msg=QMessageBox()
        age=int(self.edit.text())+4
        text='나이는' +str(age) + '입니다'     
        self.msg.setText(text)           
        self.msg.exec()

    def married(self):
        self.msg=QMessageBox()
        age=int(self.edit.text())+2
        text='나이는' +str(age) + '입니다'
        self.msg.setText(text)
        self.msg.exec()
    def first(self):
        self.msg=QMessageBox()
        age=int(self.edit.text())
        text='나이는' +str(age) + '입니다'
        self.msg.setText(text)
        self.msg.exec()

    def life(self):
        self.msg=QMessageBox()
        age=int(self.edit.text())+50
        text='나이는' +str(age) + '입니다'
        self.msg.setText(text)
        self.msg.exec()

app = QApplication()
win =MyApp()
win.show()
app.exec()