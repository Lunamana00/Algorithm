t_num = int(input())

for i in range(t_num):
    a,b = input().split()
    c = a

    for i in range(int(b)%4+3):

        a = str(int(a[-1])*int(c[-1]))[-1]

    if a != "0":
        print(a)
    else:
        print(10)
