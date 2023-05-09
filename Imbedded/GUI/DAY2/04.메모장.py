from PySide6.QtWidgets import *
from PySide6.QtGui import *

# close 할때 event 함수를 재정의 하기 위함
class MyWindow(QMainWindow):
    def closeEvent(self, event):
        global file_path
        if not edit.document().isModified():
            return
        print("1")
        if file_path is None:
            return
        ppath = file_path.split('/')[-1]
        msg = "변경 사항을 " + ppath +"에 저장하시겠습니까?"
        answer = QMessageBox.question(win,"하하호호메모장",msg,
                                      QMessageBox.Save |
                                      QMessageBox.Discard |
                                      QMessageBox.Cancel
                                      )
        if answer & QMessageBox.Save:
            save()
        elif answer & QMessageBox.Cancel:
            event.ignore()

app=QApplication()
app.setApplicationName("하하호호 메모장")
win=MyWindow()
edit = QPlainTextEdit()

win.setCentralWidget(edit)
menu=win.menuBar().addMenu("&File")

open_action=QAction("&Open")
def open_file():
    global file_path
    path = QFileDialog.getOpenFileName(win, "Open File")[0]
    if path:
        file_path = path
        edit.setPlainText(open(path).read())
open_action.triggered.connect(open_file)
open_action.setShortcut(QKeySequence("Ctrl+O"))
menu.addAction(open_action)

# file_path =None
file_path=None
save_action = QAction("&Save")
def save():
    if file_path is None:
        save_as()
    else :
        with open(file_path,"w") as f:
            f.write(edit.toPlainText())
            edit.document().isModified()
save_action.triggered.connect(save)
save_action.setShortcut(QKeySequence("Ctrl+S"))
menu.addAction(save_action)

close = QAction("&Close")
close.triggered.connect(win.close)
menu.addAction(close)

save_as_action = QAction("Save &As...")
def save_as():
    path = QFileDialog.getSaveFileName(win,"Save As")[0]
    if path:
        with open(path, "w") as f:
            f.write(edit.toPlainText())
save_as_action.triggered.connect(save_as)
save_as_action.setShortcut(QKeySequence("Ctrl+Shift+S"))
menu.addAction(save_as_action)

help_menu = win.menuBar().addMenu("&Help")
about_action = QAction("&About")
help_menu.addAction(about_action)

def show_about_dialog() :
    text ="""<center>\
    <h1>Text Editor</h1>\
    </center>
    <p>Version 1.2.3<br>
    Copyright</p>
    """
    QMessageBox.about(win, "About", text)
about_action.triggered.connect(show_about_dialog)

win.show()
app.exec()