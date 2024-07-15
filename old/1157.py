a1 = input().split(' ')

for i in a1:
    list_empt = []
    for s in i:
        list_empt.append(s.upper())
    
    list_empt = set(list_empt)
    list_empt = list(list_empt)

    max_count = 0
    max_alpha = ""
    count = 1
    for k in list_empt:
        if max_count == i.count(k)+i.count(k.lower()):
            count = 0
        elif max_count < i.count(k)+i.count(k.lower()):
            max_alpha = k
            max_count = i.count(k)+i.count(k.lower())
            count =1
    
    if count ==1:
        print(max_alpha)
    if count == 0:
        print("?")