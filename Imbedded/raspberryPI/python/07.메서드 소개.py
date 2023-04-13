# index 값 구하기
# 특정 값을 찾아서, index 값을 리턴하는 방법
# 값이 없다면 error
a= tuple([1,2,377])
print(a.index(377)) # 2

a=[1,2,55,4,11]
print(a.index(4)) # 3

# counting, List에 들어있는 값을 쉽게 Counting 가능
a=[4,3,4,3,4,3,4]
print(a.count(4)) # 4개
b=(4,3,4,3,4,3,4) 
print(b.count(3)) # 3개

# min, max
print(max(a))
print(min(b))

# 슬라이싱
# a[시작부터 : 전까지 : step]
a=[1,5,4,5,3,2]
print(a[1:5:1]) # a[1] a[2] a[3] a[4] 출력
print(a[0:6:3]) # a[0] a[3] 출력

# 문자열 파싱
a="ABCDEFG"
print(a[3:5]) # 3~5까지 글자 추출
print(a[5:3:-1]) # 5~3 글자 추출 (역순)