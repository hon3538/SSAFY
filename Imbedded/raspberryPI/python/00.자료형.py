a=10
b=3.15
c='c'
d="Hello"

e=[1,2,3] #list

f=(1,2,3) #tuple -> read only
#f=1,2,3 과 같음

#(a,b,c)=(1,2,3) tuple
#a,b,c=1,2,3 

g={"age":3,"name":"minco"} 
h={1,1,2} #set

# 문자를 아스키코드로
ord('a')


#print(''' hello i'm ''')
#주석 처리 방법
'''
a=int(input())
for i in range(1,a+1):
    b=list(map(int, input().split()))
    print('#', i, sep="", end=" ")
    if b[0] > b[1]:
        print(">")
    elif b[0]==b[1]:
        print("=")        
    else: print("<")
'''