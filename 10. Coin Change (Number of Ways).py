"""
Task: Given an array of coin denominations and a total amount, write a function to compute the total number of distinct combinations of coins that make up that amount. Assume an infinite supply of each coin.
"""

# TC: O(amount * n) where n is number of coin denominations
# SC: O(amount) for the DP array
def coin_change_ways(coins, amount):
    # dp[i] represents number of ways to make amount i
    dp = [0] * (amount + 1)
    dp[0] = 1  # Base case: 1 way to make amount 0 (use no coins)
    
    # For each coin denomination
    for coin in coins:
        # Update all amounts that can be made with this coin
        for i in range(coin, amount + 1):
            dp[i] += dp[i - coin]
    
    return dp[amount]

# 2D DP Approach (for better understanding)
# TC: O(amount * n)
# SC: O(amount * n)
def coin_change_ways_2d(coins, amount):
    n = len(coins)
    
    # dp[i][j] = ways to make amount j using first i coins
    dp = [[0 for _ in range(amount + 1)] for _ in range(n + 1)]
    
    # Base case: 1 way to make amount 0
    for i in range(n + 1):
        dp[i][0] = 1
    
    for i in range(1, n + 1):
        for j in range(1, amount + 1):
            # Don't use current coin
            dp[i][j] = dp[i - 1][j]
            
            # Use current coin (if possible)
            if coins[i - 1] <= j:
                dp[i][j] += dp[i][j - coins[i - 1]]
    
    return dp[n][amount]

if __name__ == "__main__":
    n = int(input("Enter number of coin denominations: "))
    coins = list(map(int, input("Enter coin denominations: ").split()))
    amount = int(input("Enter target amount: "))
    
    ways = coin_change_ways(coins, amount)
    print(f"Number of ways to make change: {ways}")
