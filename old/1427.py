a = input()
a_l = []
for i in a:
    a_l.append(int(i))
a_l.sort()
a_l.reverse()
ans = ""
for i in a_l:
    ans += str(i)
print(ans)