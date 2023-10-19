# Given the sorted rotated array nums of unique elements, return the minimum element of
# this array. You must write an algorithm that runs in O(log n) time. Suppose an array of
# length n sorted in ascending order is rotated between 1 and n times. For example, the
# array nums = [0,1,2,4,5,6,7] might become: [4,5,6,7,0,1,2] if it was rotated 4 times.
# [0,1,2,4,5,6,7] if it was rotated 7 times. Notice that rotating an array [a[0], a[1], a[2], ...,
# a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
# Input Format
# Number of elements list of all values Eg. 5 [3,4,5,1,2]
# Explanation: The original array was [1,2,3,4,5] rotated 3 times.
# Constraints
# Accept rotated sorted array
# Output Format
# A single integer representing minimum number in the array
# Sample Input 0
# 5
# [3,4,5,1,2]
# Sample Output 0
# 1

def minimumElement(lst) :
    start = 0
    end = len(lst)-1
    min = lst[0]
    while(start<=end) :
        mid = (start+end)//2
        print("mid :",mid)
        print("start :",start)
        print("end :",end)
        if lst[mid] > min :
            start = mid+1
        elif lst[mid] < min :
            min = lst[mid]
            end = mid
        else :
            start = mid+1
        
    return min

n = int(input("Enter the no. of elements :"))
lst = list(eval(input("Enter the elements :")))
result = minimumElement(lst)
print(result)