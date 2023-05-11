# 다단 그래프
# https://matplotlib.org/stable/gallery/index.html
# 예시 사이트에서 코드를 공부하고 원하는 plot 그리기

import matplotlib.pyplot as plt

x = [1,2,3,4,5]
y1=[10,15,20,7,23]
y2=[32,14,5,1,12]

# subplot(가로,세로,순서): plot을 가로, 세로 좌표로 나누고 그 중 몇번째 순서에 위치시킬지
plt.subplot(2,2,1)
plt.plot(x, y1, color='green', linestyle='--', marker='o')
plt.legend(['BBQ'])
plt.xlabel('month')
plt.ylabel('sales')

plt.subplot(2,2,3)
plt.plot(x, y2, color='darkblue', linestyle=':', marker='*')
plt.legend(['KFC'])
plt.xlabel('month')
plt.ylabel('sales')

plt.show()
