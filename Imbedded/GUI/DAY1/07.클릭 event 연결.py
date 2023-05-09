from PySide6.QtWidgets import *

# tbox 안에 있는 text를 출력해라
def gogo():
    print(tbox.text()) 
    
app = QApplication()
win=QWidget()


tbox = QLineEdit(win)
button = QPushButton("PUSH",win)

lay = QHBoxLayout()
lay.addWidget(tbox)
lay.addWidget(button)

win.setLayout(lay)

# 해당 버튼이 눌렸을 때 gogo 함수를 실행해라
button.clicked.connect(gogo)
win.show()
app.exec()