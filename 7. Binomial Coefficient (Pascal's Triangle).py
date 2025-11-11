"""Task: Write a function that takes two integers n and k and returns the binomial coefficient $C(n, k)$ using a dynamic programming approach. Handle potential overflows if necessary."""

# TC: O(n * k) where n and k are the input parameters
# SC: O(n * k) for the DP table
def binomial_coefficient(n, k):
    # Create DP table
    dp = [[0 for _ in range(k + 1)] for _ in range(n + 1)]
    
    # Base cases
    for i in range(n + 1):
        dp[i][0] = 1  # C(i, 0) = 1
        if i <= k:
            dp[i][i] = 1  # C(i, i) = 1
    
    # Fill the table using Pascal's identity: C(n, k) = C(n-1, k-1) + C(n-1, k)
    for i in range(2, n + 1):
        for j in range(1, min(i, k + 1)):
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
    
    return dp[n][k]

# Space Optimized Version
# TC: O(n * k)
# SC: O(k) - using only 1D array
def binomial_coefficient_optimized(n, k):
    # Optimize by using symmetry property: C(n, k) = C(n, n-k)
    if k > n - k:
        k = n - k
    
    dp = [0] * (k + 1)
    dp[0] = 1
    
    for i in range(1, n + 1):
        # Traverse from right to left to avoid overwriting
        for j in range(min(i, k), 0, -1):
            dp[j] = dp[j] + dp[j - 1]
    
    return dp[k]

if __name__ == "__main__":
    n = int(input("Enter n: "))
    k = int(input("Enter k: "))
    
    if k > n or k < 0 or n < 0:
        print("Invalid input! k should be between 0 and n.")
    else:
        result = binomial_coefficient_optimized(n, k)
        print(f"C({n}, {k}) = {result}")
