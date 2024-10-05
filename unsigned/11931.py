N = int(input())

_l = list()

for i in range(N):
    x = int(input())
    _l.append(x)
_l.sort()
_l.reverse()
for i in _l:
    print(i)