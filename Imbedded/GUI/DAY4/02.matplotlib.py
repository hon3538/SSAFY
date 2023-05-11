import matplotlib.pyplot as plt

x = [1,2,3,4,5]
y1=[10,15,20,7,23]
y2=[32,14,5,1,12]

# plot(): 꺾은선
plt.plot(x, y1, linestyle='--', marker='o')
plt.plot(x, y2, linestyle=':', marker='*')

# legend(): 범례
plt.legend(['BBQ', 'KFC'])
# xlabel/ ylabel: 축이름
plt.xlabel("month")
plt.ylabel("sales")

plt.show()

