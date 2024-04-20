import sys
import math
input = sys.stdin.readline

a = list(map(int,input().split()))
if a[0] == 1:
    a[0] = 2
num = list(range(a[0],a[1]+1))
div_list = list(range(2,int(math.sqrt(a[1]))+1))

for k in div_list:
    for s in div_list:
        if(k!=s and s%k==0):
            div_list.remove(s)

for i in num:
    buffer =1
    for s in div_list:
        if(i!=s and i%s==0):
            buffer = 0
            break
    if buffer ==1:
        print(i)


