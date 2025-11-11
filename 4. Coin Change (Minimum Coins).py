# Task: Given an array of coin denominations and a total amount, write a function to compute the fewest number of coins that you need to make up that amount. If the amount cannot be made up, return -1.

# TC: O(amount * n) where n is number of coin denominations
# SC: O(amount) for the DP array
def coin_change(coins, amount):
    # dp[i] represents minimum coins needed to make amount i
    dp = [float('inf')] * (amount + 1)
    dp[0] = 0  # Base case: 0 coins needed for amount 0
    
    # For each amount from 1 to target
    for i in range(1, amount + 1):
        # Try each coin denomination
        for coin in coins:
            if coin <= i and dp[i - coin] != float('inf'):
                dp[i] = min(dp[i], dp[i - coin] + 1)
    
    return dp[amount] if dp[amount] != float('inf') else -1

if __name__ == "__main__":
    n = int(input("Enter number of coin denominations: "))
    coins = list(map(int, input("Enter coin denominations: ").split()))
    amount = int(input("Enter target amount: "))
    
    result = coin_change(coins, amount)
    if result == -1:
        print("Amount cannot be made up with given coins")
    else:
        print(f"Minimum coins needed: {result}")
