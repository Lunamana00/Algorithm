num = int(input())

def div3(a):
    a = int(a/3)
    return a

def div2(a):
    a = int(a/2)
    return a

def minus(a):
    a = a -1
    return a

count = 0

temp_list = [num]
temp_list2 = []

while (1 not in temp_list):

    count += 1

    for i in temp_list:
        
        if i%3 == 0:
            temp_list2.append(div3(i))
        if i%2 == 0:
            temp_list2.append(div2(i))
        temp_list2.append(minus(i))

    temp_list = []
    for s in temp_list2:
        temp_list.append(s)

    temp_list2 = []

print(count)
