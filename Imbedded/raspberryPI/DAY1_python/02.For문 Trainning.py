a=[4,2,5,1,6,3,4]

for i in range(0,len(a),1):
    print(a[i],end=' ')
print('\n')
for i in a:
    print(i,end=' ')
print('\n')    
for i in range(len(a)-1,-1,-1):
    print(a[i],end=' ')
print('\n')
i=0
while i<len(a): 
    print(a[i],end=' ')
    i+=1

print('\n')
for i in range(0,len(a),1):
    if i%2==0:
        print(a[i],end=' ')
    
print('\n')
for i in range(len(a)-1,-1,-1):
    if i%2==1:
        print(a[i],end=' ')
print('\n')
for i in range(0,len(a),1):
    if(4<=a[i]<=6): print(a[i],end=' ')
