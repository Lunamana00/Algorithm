import sys
import math

M = int(sys.stdin.readline())
N = int(sys.stdin.readline())
final_list = []

for i in range(M,N+1):
    if (int(math.sqrt(i)) == math.sqrt(i)):
        final_list.append(int(i))

if bool(final_list) == 0:
    print(-1)
else:
    print(sum(final_list))
    print(min(final_list))