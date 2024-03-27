n, l = map(int,input().split())

l2 = l
print_list = []
while True:
    if l2 > 100:
        print(-1)
        break
    else:
        if l2%2 == 0:
            if (n/(l2//2))%2 != 1 :
                l2 += 1
            else:
                start = int((n/(l2//2))//2)
                for i in range(l2):
                    print_list.append(start-(l2//2)+i+1)
                if -1 in print_list:
                    l2 +=1
                    continue
                print(str(print_list)[1:-1].replace(",",""))
                break
        else:
            if (n%l2) == 0:
                if l2%2 == 1:
                    for i in range(l2):
                        print_list.append(n//l2-(l2-1)//2+i)
                    if -1 in print_list:
                        l2 +=1
                        continue
                    print(str(print_list)[1:-1].replace(",",""))
                    break
                else:
                    l2 +=1
            else:
                l2 += 1
    