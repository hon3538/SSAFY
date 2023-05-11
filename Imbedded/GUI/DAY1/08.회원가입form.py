from PySide6.QtWidgets import *
app= QApplication()
win=QWidget()

def check():
    if int(line2.text()) >= 25:
        lbl.setVisible(True)
        return
    lbl.setVisible(False)
    btn2.setVisible(True)

def register():
    mbox = QMessageBox()
    if len(line1.text()) >=4 or len(line1.text())<1 :
        mbox.setText("이름은 1~4 글자 필수")
    else :
        mbox.setText("회원가입 성공!")
    mbox.exec()

form=QFormLayout()
line1=QLineEdit()
line2=QLineEdit()
btn1=QPushButton("나이 확인")
btn2=QPushButton("회원가입")

agelay=QHBoxLayout()
agelay.addWidget(line2)
agelay.addWidget(btn1)

form.addRow("name",line1)
form.addRow("age",agelay)

lbl=QLabel("경고:나이가 너무 많습니다.")
form.addWidget(lbl)
lbl.setVisible(False)

form.addRow(btn2)
btn2.setVisible(False)
win.setLayout(form)

btn1.clicked.connect(check)
btn2.clicked.connect(register)
win.show()
app.exec()