class stack:
    
    def __init__(self, len_s=100):
        self.len_s = len_s
        self.stack = [0] * len_s
        self.pointer = 0

    def push(self, a):
        if self.pointer < self.len_s:
            self.stack[self.pointer] = a
            self.pointer += 1
        else:
            return None

    def pop(self):
        if self.pointer != 0:
            self.pointer -= 1
            save = self.stack[self.pointer]
            self.stack[self.pointer] = 0
            return save
        else:
            self.pointer = 0
            return None

    def isEmpty(self):
        return self.pointer == 0
    
    def isFull(self):
        return self.pointer == self.len_s
    
    def arg(self):
        if not self.isEmpty():
            return self.stack[self.pointer - 1]
        else:
            return None
import sys 

N = int(sys.stdin.readline())
stack_1 = stack(N)
for i in range(N):
    
    X = list(map(int,sys.stdin.readline().split()))
    if len(X)==2:
        stack_1.push(X[1])
    elif X[0] == 5:
        if(stack_1.isEmpty()):
            print(-1)
        else:
            print(stack_1.arg())
    elif X[0] == 3:
        print(stack_1.pointer)
    elif X[0] == 4:
        if(stack_1.isEmpty()):
            print(1)
        else:
            print(0)
    elif X[0] == 2:
        if(stack_1.isEmpty()):
            print(-1)
        else:
            print(stack_1.pop())
