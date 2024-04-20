N = int(input())

if len(str(N)) < 3:
    print(N)
else:
    count = 99
    for i in range(110,N):
        temp_count = 0
        str_N = str(i+1)
        temp_num = int(str_N[0]) - int(str_N[1])
        for s in range(len(str_N)-1):
            if (int(str_N[s]) - int(str_N[s+1])!=temp_num):
                temp_count = 1
                break
        if(temp_count==0):
            count+=1
    print(count)




