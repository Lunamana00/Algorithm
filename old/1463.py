num = int(input())

count = 0

while True :

    if num ==1:
        break

    if num%3 == 0:
        
        num = num//3
    
    elif (num-1)%3 == 0 and num%4 != 0:

        num = num-1
    
    elif num%2 == 0:

        num = num//2
    
    else:
        num = num-1
    
    count += 1

print(count)

