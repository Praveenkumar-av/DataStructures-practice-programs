# A critical point in a linked list is defined as a local minima. A node is a local minima if the
# current node has a value strictly smaller than the previous node and the next node.
# Note that a node can only be a local minima if there exists both a previous node and a
# next node. Given a linked list head, return an array of length 2 containing [minDistance,
# maxDistance] where minDistance is the minimum distance between any two distinct
# critical points and maxDistance is the maximum distance between any two distinct
# critical points. If there are fewer than two critical points, return [-1, -1].
# Input Format
# List of elements to be added
# Constraints
# Accept all integers
# Output Format
# Array of length 2 representing minimum and maximum distance[min,max]
# Sample Input 0
# [3,1]
# Sample Output 0
# [-1,-1]
# Sample Input 1
# [2,0,1,0,1]
# Sample Output 1
# [2,2]

class Node :
    def __init__(self) :
        self.data = None
        self.next = None

class LinkedList :
    def __init__(self) :
        self.head = None

    def addList(self,num) :
        if self.head is None :
            self.head = Node()
            self.head.data = num
        else :
            temp = self.head
            while temp.next is not None :
                temp = temp.next
            
            temp.next = Node()
            temp.next.data = num
        
    def display(self) :
        temp = self.head
        while temp is not None :
            print(temp.data)
            temp = temp.next

    def criticalPoint(self) :
        tempPrev = self.head
        temp = self.head.next
        indices = []  # store the indices of local minima
        i=0
        while temp.next is not None :
            if temp.data < tempPrev.data and temp.data < temp.next.data :
                indices.append(i)
            i+=1
            tempPrev = temp
            temp = temp.next

        if len(indices) < 2 :
            return [-1,-1]
        
        # find the min and max distance of any two critical points 
        min = indices[1]-indices[0]
        max = min
        for i in range(1,len(indices)-1) :
            temp = indices[i+1] - indices[i]
            if temp < min :
                min = temp
            elif temp > max :
                max = temp
        
        return min,max

l = LinkedList()

lst = eval(input("Enter the elements :"))
for i in lst :
    l.addList(i)

result = l.criticalPoint()
print(result)