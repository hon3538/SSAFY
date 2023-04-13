# 2차원 배열 초기화
b=[[0]*3 for _ in range(2)] # width :3, height: 2

# 순차적으로 5x5 채우기 1~25
c=[[0]*5 for _ in range(5)]
t=1
for y in range(5):
    for x in range(5):
        c[y][x]=t
        print(t,end=" ")
        t+=1
    print('\n')    

# 역순으로 5x5 채우기 25~1
d=[[0]*5 for _ in range(5)]
t=25
for y in range(5):
    for x in range(5):
        d[y][x]=t
        print(t,end=" ")
        t-=1
    print('\n')    

a=[4,2,5,1,6,3,4]
for y in range(3):
    for x in range(0,len(a),1):
        print(a[x],end=' ')
    print('\n')

for y in range(3):
    for x in range(len(a)-1,-1,-1):
        print(a[x],end=' ')
    print('\n')