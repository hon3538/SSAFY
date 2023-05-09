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

    def bye(self):
        print('bye')
        quit()
    def go(self):
        self.msg=QMessageBox()
        self.msg.setText(self.edit.text())
        self.msg.exec()



app = QApplication()
win =MyApp()
win.show()
app.exec()