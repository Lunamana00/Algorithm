T = int(input())
for i in range(T):
    T_case = input().split(" ")
    result = float(T_case[0])
    for s in range(len(T_case)-1):
        if T_case[s+1] == "@":
            result *= 3
        elif T_case[s+1] == "%":
            result += 5
        elif T_case[s+1] == "#":
            result -= 7
    print(f"{result:.2f}")