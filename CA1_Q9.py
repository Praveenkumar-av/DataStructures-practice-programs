# Given a reference to the head of a doubly-linked list and an integer, , create a new
# DoublyLinkedListNode object having data value and insert it at the proper location to
# maintain the sort.
# Sample Input
# STDIN Function
# 1 t = 1
# 4 n = 4
# 1 node data values = 1, 3, 4, 10
# 3
# 4
# 10
# 5 data = 5
# Sample Output
# 1 3 4 5 10

class Node :
    def __init__(self) :
        self.data = None
        self.next = None
        self.prev = None

class LinkedList :
    def __init__(self) :
        self.head = None
        self.last = None
    
    def insertSorted(self,value) :
        if value < self.head.data :
            n = Node()
            n.data = value
            n.next = self.head
            self.head.prev = n
            self.head = n
        else :
            temp = self.head
            while temp.next is not None :
                if value < temp.next.data :
                    n = Node()
                    n.next = temp.next 
                    n.prev = temp
                    n.next.prev = n
                    temp.next = n
                    n.data = value
                    value = None
                    break
                temp = temp.next
            
            if value is not None :
                self.addList(value)

    def addList(self,num) :
        if self.head is None :
            self.head = Node()
            self.head.data = num
            self.last = self.head
        else :
            temp = self.last
            temp.next = Node()
            temp.next.prev = temp
            temp.next.data = num
            self.last = temp.next

    def display(self) :
        temp = self.head 
        while temp is not None :
            print(temp.data)
            temp = temp.next
        
        temp = self.last
        while temp is not None :
            print(temp.data)
            temp = temp.prev

l = LinkedList()

n = int(input("Enter the no. of elements :"))
print("Enter the elements :")
for i in range(n) :
    num = int(input())
    l.addList(num)

num = int(input("Enter the element to insert :"))
l.insertSorted(num)

l.display()