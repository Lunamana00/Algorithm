T = list(map(int,input().split(" ")))
num_list = list(map(int,input().split(" ")))

sum = 0
for i in range(T[0]):
    for s in range(T[0]):
        for k in range(T[0]):
            if len({num_list[i],num_list[s],num_list[k]})==3:
                if num_list[i]+num_list[s]+num_list[k] <= T[1]:
                    if num_list[i]+num_list[s]+num_list[k] > sum:
                        sum = num_list[i]+num_list[s]+num_list[k]

print(sum)