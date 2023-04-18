# list 안에 for문을 내장시킬 수 있다

a=[0 for i in range(10)] # [0,0,0,...]
a=[i for i in range(10)] # [0,1,2,...]
a=[i+2 for i in range(10)] # [0,2,4,...]

# list 초기화 세가지 방법
a=[0]*5
b=[0 for i in range(5)]
c=[0,0,0,0,0]


# 객체 i는 의미가 없는 경우, 변수 이름을 '_' 로 쓰는것을 권장하고 있다
b =[0 for _ in range(5)]

# list 안에 for와 if를 함께 사용 가능하다.
# 하지만 점점 복잡해진다.
a = [i for i in range(10) if i%2==0]



