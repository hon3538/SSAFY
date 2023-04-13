b=[3,3,2,6,2]
a=[0]*7

for i in range(0,len(b),1):
    a[b[i]]+=1

for i in range(1,7,1):
    print(a[i],end=" ")
    
# 만약 index가 문자열이라면 ? hash map 이용해야한다
# hashmap 역할이 Dictionary 다

#Dictionary 생성 두 가지 방법
a=dict()
a['HI']=55
a['BBQ']='KFC'

#또는
a={'HI':55,'BBQ':'KFC'} # key:value
print(a['BBQ'])

lst=['MC','BTS','BTS','MC']
di =dict()
for i in lst:
    di[i]=0

for i in lst:
    di[i]+=1
    
# 사용자가 숫자를 key 값으로 사용하면 문자열인지 숫자인지 구분이 안 가므로 다 str()처리 해준다
list =['ABE',53,-99,-99,124]
d=dict()
for i in list : d[str(i)]=0
for i in list:
    d[str[i]]+=1

# 안에 key값이 존재하는지 확인하는 법 -> in 사용
if('abc' in list): print("exist")
if('ABC' not in list): print("not exist")

# keys()와 for문을 이용하여 모든 키값을 출력할 수 있다
d={'KFC':10,'MC':20,'MOMS':30}
print(d.keys()) # key들만 출력
for i in d.key():
    print(i, d[i]) # key value 출력
