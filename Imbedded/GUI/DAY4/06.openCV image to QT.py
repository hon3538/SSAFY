from PySide2.QtCore import *
from PySide2.QtGui import *
from PySide2.QtWidgets import *
from opencv import Ui_MainWindow
import numpy
import cv2

class MyApp(QMainWindow,Ui_MainWindow):
    def __init__(self):
        super().__init__()
        Ui_MainWindow.setupUi(self, self)
        self.main()

    def main(self):
        self.img=cv2.imread('image.jpg')
        self.img=self.processingImage(self.img)
        self.printImage(self.img, self.pic)

    def processingImage(self,img):
        # blur 처리
        # img=cv2.blur(img,(55,55))

        # image color 변경
        # img = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

        # 흑과 백으로 변경
        #img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        #kernel = numpy.ones((3,3))
        #img = cv2.morphologyEx(img, cv2.MORPH_GRADIENT, kernel)

        #Canny : 테두리 Detect Algorithm
        img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        ret, img=cv2.threshold(img,120,255,cv2.THRESH_BINARY)
        #img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
        #img = cv2.Canny(img,50,200)

        return img

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
