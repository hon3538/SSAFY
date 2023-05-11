from PySide6.QtWidgets import *
from mat import Ui_MainWindow
from matplotlib import pyplot
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg
import numpy as np
class MyApp(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.main()
        
    def main(self):
        # figure 객체 : Plot 데이터 관리
        # self.figure=pyplot.Figure()
        self.figure=pyplot.Figure()
        # canvas 객체 : View 역할
        self.canvas =FigureCanvasQTAgg(self.figure)
        # Box Layout 에 Canvas 라는 위젯 추가
        self.lay.addWidget(self.canvas)
        self.graph1=self.figure.add_subplot(1,3,1)
        self.graph2 = self.figure.add_subplot(1, 3, 2)
        self.graph3 = self.figure.add_subplot(1, 3, 3)
    def chart1(self):
        a = [i for i in range(10)]
        # rand() -> 실수 난수 생성, 10은 사이즈(개수)
        v = np.random.rand(10)
        self.graph1.bar(a, v)
        self.graph2.scatter(a, v)
        self.graph3.plot(a, v)
        self.figure.suptitle('Categorical Plotting')
        self.canvas.draw()

    def chart2(self):
        line = [1,2,3]
        self.graph2.bar(line,[10,50,30])
        self.canvas.draw()

app = QApplication()
win = MyApp()
win.show()
app.exec()
