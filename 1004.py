test_case = int(input())

for i in range(test_case):

    a,b,c,d = map(int,input().split())
 
    spot1_x = a
    spot1_y = b
    spot2_x = c
    spot2_y = d

    planet_num = int(input())
    planet_loc = list()

    for s in range(planet_num):

        a,b,c = map(int,input().split())
        planet_loc.append([a,b,c])

    spot1_planet = []
    spot2_planet = []

    for i in planet_loc:
        if (spot1_x - i[0])**2 + (spot1_y - i[1])**2 < i[2]**2:
            spot1_planet.append(i)
        if (spot2_x - i[0])**2 + (spot2_y - i[1])**2 < i[2]**2:
            spot2_planet.append(i)
    count = 0
    for i in spot1_planet:
        if (spot2_x - i[0])**2 + (spot2_y - i[1])**2 > i[2]**2:
            count += 1
    for i in spot2_planet:
        if (spot1_x - i[0])**2 + (spot1_y - i[1])**2 > i[2]**2:
            count += 1
    print(count)


