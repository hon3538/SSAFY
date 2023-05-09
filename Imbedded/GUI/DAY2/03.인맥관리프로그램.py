from PySide6.QtWidgets import *
from PySide6.QtGui import *

app = QApplication()
win = QMainWindow()
win.setGeometry(100,100,500,500)

menu = win.menuBar()
menuFile=menu.addMenu("메뉴")
menuExit=menu.addMenu("종료")

add=QAction("추가",win)
rm=QAction("제거",win)
menuAdd=menuFile.addAction(add)
menuDel=menuFile.addAction(rm)
main = QWidget()
win.setCentralWidget(main)

form=QFormLayout()
lbl = QLabel("인맥을 관리합시다")
lbl.adjustSize()
form.addRow("",lbl)

name=QLineEdit()
form.addRow("name",name)

hlay=QHBoxLayout()
addBut=QPushButton("추가")
delBut=QPushButton("제거")
hlay.addWidget(addBut)
hlay.addWidget(delBut)

form.addRow(hlay)
main.setLayout(form)

open = QAction("열기",win)
menuFile.addAction(open)

bar = win.statusBar()
bar.showMessage("메뉴를 클릭해보세요")

list={}
cnt=0
def _add_():
    mbox=QMessageBox()
    if len(name.text())==0 :
        mbox.setText("추가할 이름을 입력해주세요")
        mbox.exec()
        return
    if list.get(name.text(),0) !=0 :
        mbox.setText("이미 이름이 존재합니다")
        mbox.exec()
        return
    list[name.text()]=1
    mbox.setText("이름을 성공적으로 추가했습니다")
    mbox.exec()
addBut.clicked.connect(_add_)

def _del_():
    mbox=QMessageBox()
    if len(name.text())==0 :
        mbox.setText("제거할 이름을 입력해주세요")
        mbox.exec()
        return
    if list.get(name.text(),0) ==0 :
        mbox.setText("이미 이름이 존재하지 않습니다")
        mbox.exec()
        return
    del list[name.text()]
    mbox.setText("이름을 제거했습니다")
    mbox.exec()
delBut.clicked.connect(_del_)


win.show()
app.exec()