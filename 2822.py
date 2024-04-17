import copy

l_1 = []

for i in range(8):
    l_1.append(int(input()))
    
l_2 = l_1.copy()
l_1.sort()

use_list = l_1[3:]

ans_list = []
for i in use_list:
    ans_list.append(l_2.index(i)+1)
ans_list.sort()

print(sum(use_list))
print(ans_list[0],ans_list[1],ans_list[2],ans_list[3],ans_list[4])