def gcd(a,b):
    if(a!=0):
        if(b%a):
            return gcd(b%a,a)
        else:
            return a

a = list(map(int,input().split()))
b = list(map(int,input().split()))

new_c = [a[0]*b[1]+b[0]*a[1],a[1]*b[1]]

var_1 = a[0]*b[1]+b[0]*a[1]
var_2 = a[1]*b[1]

count = 0

while(True):
    var_r = gcd(var_1,var_2)
    if(var_r > 1):
        var_1 = var_1/var_r
        var_2 = var_2/var_r
    else:
        break

print(int(var_1),int(var_2))
