# coin change problem with optimal solution

def minNoCoins(coins,total) :
    minCoins = [0] + [float('inf')]*total
    
    for i in range(1,total+1) :
        for coin in coins :
            if(i >= coin) :
                minCoins[i] = min(minCoins[i-coin]+1, minCoins[i])
        
        print(minCoins)
    
    if(minCoins[total] == float('inf')) :
        return -1
    else :
        return minCoins[total]

print("Enter the coins :")
s = input()
print("Enter the amount :")
total = int(input())
coins = s.split()
for i in range(len(coins)) :
    coins[i] = int(coins[i])


result = minNoCoins(coins,total)
print(result)