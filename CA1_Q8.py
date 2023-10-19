# Game of Two stacks

def maxMove(a,b,x) :
    total = max = i = j = 0

    # add every element in a upto total less than x
    while i < len(a) and total+a[i] <= x :
        total += a[i]
        i+=1
        max += 1

    # add element in b
    while j < len(b) and i >= 0:
        total += b[j]
        j += 1

        # remove element from a
        while i > 0 and total > x :
            i -= 1
            total -= a[i]
        
        if max < i+j and total <= x :
            max = i+j
    
    return max

a = eval(input("Enter the first stack :"))
b = eval(input("Enter the Second stack :"))
x = int(input("Enter x :"))
result = maxMove(a,b,x)
print(result)