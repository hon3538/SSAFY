from PySide2.QtCore import *
from PySide2.QtGui import *
from PySide2.QtWidgets import *
from opencv import Ui_MainWindow
import numpy
import cv2
from time import *

class MyThread(QThread):
    mySignal = Signal(QPixmap, QPixmap) #두 개의 영상 전송위해

    def __init__(self):
        super().__init__()
        self.cam = cv2.VideoCapture(0)
        self.cam.set(3,480)
        self.cam.set(4, 320)

    def run(self):
        while True:
            ret, self.img = self.cam.read()
            if ret:
                self.printImage(self.img)
            sleep(0.1)

    def printImage(self, imgBGR):
        # 첫번째 영상세팅
        imgRGB =cv2.cvtColor(imgBGR, cv2.COLOR_BGR2RGB)
        h, w, byte = imgRGB.shape
        img = QImage(imgRGB, w, h ,byte*w, QImage.Format_RGB888)
        pix_img = QPixmap(img)
        # 두번째 영상세팅
        imgGray =cv2.cvtColor(imgBGR, cv2.COLOR_BGR2GRAY)
        imgCanny=cv2.Canny(imgGray, 100, 100)
        img2 = QImage(imgCanny, w, h ,imgCanny.strides[0], QImage.Format_Grayscale8)
        pix_img2 = QPixmap(img2)

        self.mySignal.emit(pix_img, pix_img2)

class MyApp(QMainWindow,Ui_MainWindow):
    def __init__(self):
        super().__init__()
        Ui_MainWindow.setupUi(self, self)
        self.main()

    def main(self):
        self.th = MyThread()
        self.th.mySignal.connect(self.setImage)

    def setImage(self, img, img2):
        self.pic1.setPixmap(img)
        self.pic2.setPixmap(img2)

    def mode(self):
        pass

    def play(self):
        self.th.start()

    def closeEvent(self,event):
        self.th.terminate()
        self.th.wait(3000)
        self.close()

app=QApplication()
win = MyApp()
win.show()
app.exec_()