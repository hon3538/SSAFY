from PySide6.QtWidgets import *
app = QApplication()

win=QWidget()
win.setWindowTitle("euiseon")
win.setGeometry(0,0,400,300)
btn1 = QPushButton("One")
btn2 = QPushButton("Two")
btn3 = QPushButton("THREE")
btn4 = QPushButton("One")
btn5 = QPushButton("Two")
btn6 = QPushButton("THREE")
mainLay=QVBoxLayout()
bodyLay=QVBoxLayout()
headLay=QHBoxLayout()

headLay.addWidget(btn1)
headLay.addWidget(btn2)
headLay.addWidget(btn3)

bodyLay.addWidget(btn4)
bodyLay.addWidget(btn5)
bodyLay.addWidget(btn6)

mainLay.addLayout(headLay)
mainLay.addLayout(bodyLay)
win.setLayout(mainLay)

win.show()

app.exec()