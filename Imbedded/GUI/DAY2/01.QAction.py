from PySide6.QtWidgets import *
from PySide6.QtGui import *

app = QApplication()
win = QMainWindow()
win.setGeometry(100,100,500,500)

menu = win.menuBar()
menuFile=menu.addMenu("File")
menuEdit=menu.addMenu("Edit")
menuExit=menu.addMenu("Exit")

# 내용을 따로 Widget으로 만들어서 공간을 만든다
# main window와 내용이 겹치기 않기 위해서
main = QWidget()
win.setCentralWidget(main)
lbl = QLabel("BBQ 맛있다",main)
lbl.adjustSize()

open = QAction("열기",win)
search = QAction("찾기",win)
close = QAction("닫기",win)
menuFile.addAction(open)
menuFile.addAction(search)
menuFile.addAction(close)

font=QAction("글꼴",win)
form=QAction("서식",win)
menuEdit.addAction(font)
menuEdit.addAction(form)
bar = win.statusBar()
bar.showMessage("나는 지금도 배고프다")
win.show()
app.exec()