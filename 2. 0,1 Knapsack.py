# Task: You are given the weights and values of n items and a knapsack that can hold a maximum weight W. You cannot break an item. Determine the maximum total value you can put into the knapsack.

# TC: O(n * W) where n is number of items and W is knapsack capacity
# SC: O(n * W) for the DP table
def knapsack(W, weights, values, n):
    # Create DP table
    dp = [[0 for _ in range(W + 1)] for _ in range(n + 1)]
    
    # Build table dp[][] in bottom-up manner
    for i in range(1, n + 1):
        for w in range(1, W + 1):
            if weights[i - 1] <= w:
                # Max of including or excluding current item
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], 
                               dp[i - 1][w])
            else:
                # Can't include current item
                dp[i][w] = dp[i - 1][w]
    
    return dp[n][W]

# Space Optimized Version
# TC: O(n * W)
# SC: O(W) - using only 1D array
def knapsack_optimized(W, weights, values, n):
    dp = [0] * (W + 1)
    
    for i in range(n):
        # Traverse from right to left to avoid overwriting
        for w in range(W, weights[i] - 1, -1):
            dp[w] = max(dp[w], values[i] + dp[w - weights[i]])
    
    return dp[W]

if __name__ == "__main__":
    n = int(input("Enter number of items: "))
    W = int(input("Enter knapsack capacity: "))
    
    weights = list(map(int, input("Enter weights: ").split()))
    values = list(map(int, input("Enter values: ").split()))
    
    max_value = knapsack_optimized(W, weights, values, n)
    print(f"Maximum value: {max_value}")
