def find(numSet):
    # Step 2: Iterate through each number in the set
    longest = 0
    for n in numSet:
        # Check if it's part of a sequence
        if n - 1 not in numSet:
            currentNum = n
            currentStreak = 1

            # Step 4: Count the sequence length
            while currentNum + 1 in numSet:
                currentNum += 1
                currentStreak += 1

            # Step 5: Update the longest streak
            longest = max(longest, currentStreak)

    return longest


numSet = list(map(int, input().split()))
result = find(numSet)
print(result)
