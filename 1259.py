input_lst = []
while(True):
    a = input()
    if int(a)!=0:
        input_lst.append(a)
    else:
        break
print(input_lst)

for i in input_lst:
    if len(i) == 1:
        print("yes")
    else:
        for s in range(len(i)//2):
            if i[s] != i[len(i)-s-1]:
                switch = 0
                break
            switch = 1
        if(switch==1):
            print("yes")
        else:
            print("no")
