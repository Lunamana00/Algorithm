T = int(input())
count = 2
while(T>1):
    if(T%count)==0:
        print(count)
        T = T/count
    else:
        count+=1
