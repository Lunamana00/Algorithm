import math

test_case = int(input())

for case in range(test_case):
    west, east = map(int,input().split())
    print(int((math.factorial(east)//math.factorial(east - west))//math.factorial(west)))