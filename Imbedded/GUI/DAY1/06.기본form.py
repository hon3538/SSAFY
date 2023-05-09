from PySide6.QtWidgets import *
app = QApplication()

win=QWidget()

# 해당 widget 이 win 위젯에 소속되도록 한다
lineEdit = QLineEdit(win)
# 해당 widget 이 win 위젯에 소속되도록 한다
button = QPushButton("HUHU",win)

lay = QHBoxLayout()
lay.addWidget(lineEdit)
lay.addWidget(button)

win.setLayout(lay)

win.show()
app.exec()