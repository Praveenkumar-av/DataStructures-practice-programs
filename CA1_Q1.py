# Design a stack that supports push, pop, peek and retrieving the minimum element in
# constant time. Returns -1 is the stack is empty. You must implement a solution with O(1)
# time complexity for each function.
# Input Format
# First Line should get the number of operations to be performed on stack. List of
# Operations to be performed in the Stack. 
# Eg 6
# ["Stack","push","pop","push","peek","pop"] [0,15,0,25,0,0]
# 0 indicates no input
# Constraints
# Accept all integers between 1 to 500
# Output Format
# Displays the value of pop, peek and minimum value in the stack as a list
# Sample Input 0
# 6
# ["Stack","push","pop","push","push","minval"]
# [0,12,0,39,90,0]
# Sample Output 0
# [12,39]

class Stack :
    def __init__(self) :
        self.lst = []
        self.result = []
        self.minval = None

    def push(self,x) :
        if self.minval is None :
            self.minval = x
            self.lst.append(x)
        elif x >= self.minval :
            self.lst.append(x)
        else :
            self.lst.append((2*x)-self.minval)
            self.minval = x

    def pop(self) :
        try :
            x = self.lst.pop()
            # if self.minval is None :
            #     self.result.append(-1)
            if x < self.minval :
                self.minval = (2*self.minval) - x
                self.result.append(self.minval)
            else :
                self.result.append(x)

        except IndexError :
            self.result.append(-1)

    def minVal(self) :
        self.result.append(self.minval)


n = int(input("Enter the no. of operations :"))
op = list(eval(input("Enter the operations :")))
val = list(eval(input("Enter the values :")))

if n != len(op) or n != len(val) :
    print("Enter ",n,"operations")
    exit(0)

for i in range(n) :
    if op[i] == 'stack' :
        s = Stack()
    elif op[i] == 'push' :
        s.push(int(val[i]))
    elif op[i] == 'pop' :
        s.pop()
    elif op[i] == 'minval' :
        s.minVal()    

print(s.result)