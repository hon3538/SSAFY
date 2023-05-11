import numpy as np
a= np.zeros((5,4))
a.fill(5)
print(a)
for i in range(2):
    for j in range(4):
        a[i+2][j]=7

print(a)

#사이즈
y, x=a.shape
print(y,x)

# tolist() : ndarray -> list 변경
vect = a.tolist()
print(vect, type(vect))

# array() : list ->ndarray 변경
b = np.array(vect)
print(b,type(b))

#1~10 사이 랜덤값으로 (2,3) 크기 ndarray 채움
a = np.random.randint(1,10,(2,3))
print(a)


def p(a):
    for i in range(3):
        for j in range(3):
            print(a[i][j],end='')
        print()

#-5~5 사이 랜덤값으로 (3,3) 크기 ndarray 채움
a = np.random.randint(-5,5,(3,3))
p(a)
a = np.random.randint(-5,5,(3,3))
p(a)
a = np.random.randint(-5,5,(3,3))
p(a)