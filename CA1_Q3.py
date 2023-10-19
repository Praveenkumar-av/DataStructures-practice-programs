# Start browsing from homepage,move forward and backwards to other url.
# BrowserHistory(string homepage) Initializes datastructure with the homepage of the
# browser. void visit(string url) Visits url from the current page. It clears up all the forward
# history. string back(int steps) Move steps back in history. If you can only return x steps
# in the history and steps > x, you will return only x steps. Return the current url after
# moving back in history at most steps. string forward(int steps) Move steps forward in
# history. If you can only forward x steps in the history and steps > x, you will forward only
# x steps. Return the current url after forwarding in history at most steps.
# Input Format
# 11
# ["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]
# ["psgtech.edu","google.com","facebook.com","youtube.com",1,1,1,"linkedin.com",2,2,7]
# Constraints
# Limit the number of operations to a maximum of 15
# Output Format
# [null,null,null,null,"facebook.com","google.com","facebook.com",null,"linkedin.com","goo
# gle.com","psgtech.edu"]

n = int(input("Enter the no. of elements :"))
op = list(eval(input("Enter the operations :")))
data = list(eval(input("Enter the data :")))
result = []
browse = []

for i in range(n) :
    if op[i] == 'BrowserHistory' :
        browse.append(data[i])
        result.append("null")
        current = 0
        top = 0
        print(result)
        print(browse,'\n')

    elif op[i] == 'visit' :
        print("Current = ",current)
        browse = browse[0:current+1]
        browse.append(data[i])
        result.append("null")
        current += 1
        top = current
        print(result)
        print(browse,'\n')

    elif op[i] == 'back' :
        if current - data[i] < 1 :
            current = 0
        else :
            current -= data[i]
        result.append(browse[current])
        print(result)
        print(browse,'\n')

    elif op[i] == 'forward' :
        if current + data[i] >= top :
            current = top
        else :
            current += data[i]
        result.append(browse[current])
        print(result)
        print(browse,'\n')

print(result)