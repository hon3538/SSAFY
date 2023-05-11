from PySide6.QtWidgets import *
from mat import Ui_MainWindow
from matplotlib import pyplot
from matplotlib.backends.backend_qt5agg import FigureCanvasQTAgg

class MyApp(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.main()
        
    def main(self):
        # figure 객체 : Plot 데이터 관리
        self.figure=pyplot.Figure()
        # canvas 객체 : View 역할
        self.canvas =FigureCanvasQTAgg(self.figure)
        # Box Layout 에 Canvas 라는 위젯 추가
        self.lay.addWidget(self.canvas)
        self.graph1 = self.figure.add_subplot(1,2,1)
        self.graph2 = self.figure.add_subplot(1,2,2)

    # chart1 버튼 눌렀을 때, 그래프를 그려줌
    # 안의 데이터는 각 라인의 데이터임
    # line list의 순서대로 데이터가 할당됨
    # 즉 line list 크기와, plot에 들어가는 data list 크기가 같아야함
    def chart1(self):
        line = [1,2,3]
        self.graph1.plot(line,[10,40,50])
        self.graph1.plot(line,[32,35,19])
        self.graph1.plot(line,[4,53,76])
       # self.graph1.plot(line, [10, 10, 10])
        self.canvas.draw()

    def chart2(self):
        line = [1,2,3]
        self.graph2.bar(line,[10,50,30])
        self.canvas.draw()

app = QApplication()
win = MyApp()
win.show()
app.exec()
