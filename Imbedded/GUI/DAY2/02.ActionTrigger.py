from PySide6.QtWidgets import *
from PySide6.QtGui import *

app = QApplication()
win = QMainWindow()
win.setGeometry(100,100,500,500)

menu = win.menuBar()
menuFile=menu.addMenu("File")

main = QWidget()
win.setCentralWidget(main)
lbl = QLabel("BBQ 맛있다",main)
lbl.adjustSize()

open = QAction("열기",win)
menuFile.addAction(open)

bar = win.statusBar()
bar.showMessage("메뉴를 클릭해보세요")

def _open_():
    bar.showMessage("열기누름")
open.triggered.connect(_open_)

win.show()
app.exec()