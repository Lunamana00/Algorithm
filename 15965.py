import math

a = int(input())
count = 0
b = 2
while(True):
    buffer = 0
    for i in range(2,int(math.sqrt(b))+1):
        if(b!=i and b%i==0):
            buffer = 1
            break
    if buffer == 0:
        count += 1
    if count == a:
        break
    b+=1

print(b)
