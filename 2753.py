T = int(input())

if (T%4)==False:
    if (T%400)==False:
        print(1)
    elif (T%100)==False:
        print(0)
    else:
        print(1)
else:
    print(0)
