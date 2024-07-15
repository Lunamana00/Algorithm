class stack:
    def __init__(self):
        self.list=[]
    def push(self,item):
        self.list.append(item)
    def pop(self):
        return self.list.pop()
    def peak(self):
        return self.list[-1]
    def isempty(self):
        if len(self.list)==0:
            return True
        else:
            return False
s=stack()


import sys
a=int(sys.stdin.readline())

for i in range(a):
    correct=True
    alist=list(sys.stdin.readline()[:-1])
    if alist.count("(")==alist.count(")"):
        if alist[0]=="("and alist[len(alist)-1]==")":
            for c in range(0,len(alist)):
                s.push(alist[c])
                if s.list.count("(")>=s.list.count(")"):
                    pass
                else:
                    correct=False
                    break
        else:
            correct=False
    else:
        correct=False

    if correct:
        print("YES")
    else:
        print("NO")