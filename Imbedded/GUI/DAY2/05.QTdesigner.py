# .ui 를 프로젝트 경로와 같은곳에 저장하고
# .py로 변환한다
# Terminal 창에서 pyside2-uic (파일명.ui) o (파일명.py) 입력
# 버튼에 함수 연결은 QT designer에서 시그널/슬롯 모드

from PySide6.QtWidgets import *
from PySide6.QtUiTools import *
from test import Ui_MainWindow

class MyApp(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.ui = Ui_MainWindow()
        self.ui.setupUi(self)

    def hoho(self):
        print('hoho')
    def haha(self):
        print('haha')
        
app = QApplication()
win =MyApp()
win.show()
app.exec()