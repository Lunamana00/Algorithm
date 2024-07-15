class stack:
    
    def __init__(self,len_s=100):
        self.len_s = len_s
        self.stack = [0]*len_s
        self.pointer = 0

    def push(self,a):
        if(self.pointer <= self.len_s):
            self.stack[self.pointer] = a
            self.pointer += 1
        else:
            print("범위 벗어남")
            
    def pop(self):
        if(self.pointer != 0):
            self.pointer -= 1
            save = self.stack[self.pointer]
            self.stack[self.pointer] = 0
        else:
            print("범위 벗어남")
        return save
        
    def isEmpty(self):
        return self.pointer == 0
    
    def isFull(self):
        return self.pointer == self.len_s
    
    def arg(self):
        return self.stack[self.pointer-1]

N = int(input())
L_1 = list(map(int,input().split()))
if(N == 1):
    print("Nice")
else:
    stack_row = stack(N)
    for i in range(N):
        stack_row.push(L_1[N-i-1])

    stack_col = stack(N)

    num = 1

    save = stack_row.pop()

    while(save==num):
        num += 1
        if(stack_row.isEmpty() == False):
            save = stack_row.pop()
        else:
            print("Nice")
    if (stack_row.isEmpty() == False):
        stack_col.push(save)

    switch = 1
    while(stack_row.isEmpty() == False or stack_col.isEmpty()==False):
        save_row = stack_row.arg()
        save_col = stack_col.arg()
        print("=================")
        print(stack_col.stack)
        print(stack_row.stack)
        if(save_row == num):
            stack_row.pop()
            num += 1
        elif(save_col == num):
            stack_col.pop()
            num += 1
        elif(save_row < save_col or save_col == 0):
            stack_col.push(stack_row.pop())
        else:
            print("Sad")
            switch = 0
            break

    if switch ==1:
        print("Nice")