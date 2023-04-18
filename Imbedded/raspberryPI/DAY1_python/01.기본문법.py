for i in range(10):
    print(i)
    
#input() 문자열로 입력이됨, 수 입력시 반드시 변환 필요
#split() 파이썬은 띄어쓰기를 엔터로 취급 안함, 띄어쓰기 인경우 split으로 나눠줘야함
a, b = input().split()
print(a)
print(b)

#map() 한꺼번에 int로 만드는 방법(맵핑)
a=list(map(int,input().split()))
for i in a:
    print(i)

#if
if a!=b:
    print("no")
    
#for
for i in range(5,0,-1):
    print(i,end=' ') # 한번 출력하고 한칸 띄어라..

#list
a=[1,2,5,6,3,9,-5]
a.append(5) #list에 추가 가능
a[0] # index로 접근
len(a) # list 원소 개수 

#함수
c=1
def ABC(a,b):
    global c # 
    print(c+a+b)

#for each
a=[1,2,3,4,5]
for i in a:
    print(1)
    
#and or
if a==3 and b==5:
    print("#")
#else if
if a==3:
    print("#")
elif a==4:
    print("@")
else :
    print("$")
