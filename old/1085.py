x,y,w,h = map(int,input().split())

shortest = []
shortest.append(x)
shortest.append(y)
shortest.append(w-x)
shortest.append(h-y)

print(min(shortest))
    