from PySide6.QtWidgets import *

'''
QWidget
은 하나의 Window 이다

app
Application 에 대한 인스턴스
이벤트를 받는다
App 전체에 대한 정보가 담겨있다

Widget
하나의 윈도우 이다
화면을 구성하고 , widget 내부에 widget 추가 가능
'''
app = QApplication()

# label=QLabel("Hello World")
# label.show()
# w=QWidget()
# w.show()
btn=QPushButton("KFC")
btn.show()

app.exec()