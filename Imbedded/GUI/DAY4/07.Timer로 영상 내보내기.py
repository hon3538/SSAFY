from PySide2.QtCore import *
from PySide2.QtGui import *
from PySide2.QtWidgets import *
from opencv import Ui_MainWindow
import numpy
import cv2
from time import *

class MyApp(QMainWindow,Ui_MainWindow):
    def __init__(self):
        super().__init__()
        Ui_MainWindow.setupUi(self, self)
        self.main()

    def main(self):
        self.cam = cv2.VideoCapture(0)
        self.cam.set(3,480)
        self.cam.set(4,320)
        self.tm =QBasicTimer()

    def mode(self):
        pass

    def timerEvent(self, event):
        ret, self.img = self.cam.read()
        self.printImage(self.img, self.pic1)

    def play(self):
        self.tm.start(100,self)

    def printImage(self, imgBGR, pic):
        # OpenCV  는 BGR 사용, Qt는RGB를 사용하기 때문에 convert
        imgRGB = cv2.cvtColor(imgBGR, cv2.COLOR_BGR2RGB)
        # OpenCV의 객체 Numpy.ndarray를 QImage객체로 변경(QT 사용위함)
        h, w, byte = imgRGB.shape
        # QImage : 이미지 파일을 읽어 ㅁ모리에 올려, 픽셀 편집 가능
        img=QImage(imgRGB, w, h, byte*w, QImage.Format_RGB888)
        # QPixmap : 메모리에 이쓴ㄴ 이미지 파일을 화면에 출력
        pic.setPixmap(QPixmap(img))

app=QApplication()
win = MyApp()
win.show()
app.exec_()
