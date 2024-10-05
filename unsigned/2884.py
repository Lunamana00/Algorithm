a1 = input()
a2 = a1.split(" ")

for i in range(len(a2)):
    a2[i] = int(a2[i])

if int(a2[1]) - 45 < 0 :
    if int(a2[0]) == 0:
        a2[0] = 23
    else:
        a2[0] = int(a2[0])-1
    a2[1] = int(a2[1]) + 15
else:
    a2[1] = int(a2[1])-45

print(a2[0],a2[1])