import math

N = int(input())
r_v = 2
while(True):
    if len(str(N)) == 1:
            switch = 0
            r_v = N
            if N == 1:
                r_v = 2
    else:
        for i in str(N):
            for s in range(len(str(N))//2):
                if str(N)[s] != str(N)[len(str(N))-s-1]:
                    switch = 1
                    break
                switch = 0

    if (switch==0):
        out_switch = 1
        root = int(math.sqrt(N))
        for i in range(2,root+1):
            if(int(N/i)*i==N):
                out_switch = 0
                break
            else:
                r_v = N
        if(out_switch == 1):
            break
    N+=1

print(r_v)