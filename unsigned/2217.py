N = int(input())

min_list = []

for i in range(N):
    x = int(input())
    min_list.append(x)

min_list.sort()
list_len = len(min_list)
max_value = 0
for i in min_list:

    if(max_value < i*list_len):
        max_value = i*list_len
    list_len -= 1

print(max_value)