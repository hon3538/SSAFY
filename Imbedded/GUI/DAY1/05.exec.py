from PySide6.QtWidgets import *
app = QApplication()

win=QWidget()

alert = QMessageBox()
alert.setText("HI HI HI")
alert.exec()

win.show()

app.exec()

# exec 을 통해 독립적인 메세지 박스를 띄운다