# Coin change problem using recursion
# Program to find the minimum no. of coins to sum up total amount

from math import inf

class Sample :
    result = inf
    def __init__(self, coins, total) :
        self.coins = coins
        self.total = total
    
    def minvalue(self, sum, count) :
        if(sum == self.total) :
            if(count < Sample.result) :
                Sample.result = count
        elif(sum < total) :
            count += 1
            for coin in coins :
                # sum += int(coin)  
                self.minvalue(sum+int(coin),count)
                # sum -= int(coin)

print("Enter the coins as list :")
coins = eval(input())
print("Enter the total amount :")
total = int(input())

s = Sample(coins,total)
s.minvalue(0,0)
print(Sample.result)
