def func_dfs(list,start_num):
    temp_num = 100000
    temp_list = []
    for i in range(len(list)):
        for s in list[i]:
            if str(start_num) in s:
                temp_list.append
                for t in list[i]:
                    if t != start_num:
                        if int(t)< temp_num:
                            temp_num = int(t)

    print(temp_list)
    return_list = []
    for i in temp_list:
        list[int(i)] = ""

    for i in range(len(list)):
        if bool(list[i]) == True:
            return_list.append(list[i])
    
    print(return_list)

    return temp_num, return_list

input_1st = input()
input_list = input_1st.split(" ")

static_dot = input_list[0]
line_num = input_list[1]
start_num = input_list[2]

ans = []

line_list = []
for i in range(int(line_num)):
    line = input()
    line_list.append(line.split(" "))

func_dfs(line_list,start_num)
final_string = start_num + " "

while bool(line_list):
    start_num, line_list = func_dfs(line_list,start_num)
    print(line_list,start_num)
    final_string += str(start_num)
print(final_string)
