t_case = int(input())

memo = [[1,0],[0,1],[1,1]]


def fibonacci(n):
    
    if n == 0 or n == 1 or n == 2:
       pass
    
    else:
        if len(memo) <= n:
            for i in range(len(memo),n+1):
                memo.append([memo[i-1][0]+memo[i-2][0],memo[i-1][1]+memo[i-2][1]])
    print(memo[n][0],memo[n][1])

for i in range(t_case):
    a = int(input())
    fibonacci(a)
    