# Task: Given an array p[] which represents the dimensions of a chain of matrices (matrix A_i has dimension p[i-1] x p[i]), find the minimum number of scalar multiplications needed to multiply the chain.

# TC: O(n^3) where n is the number of matrices
# SC: O(n^2) for the DP table
def matrix_chain_multiplication(p):
    n = len(p) - 1  # Number of matrices
    
    # dp[i][j] represents minimum multiplications for matrices from i to j
    dp = [[0 for _ in range(n)] for _ in range(n)]
    
    # len is chain length
    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            dp[i][j] = float('inf')
            
            # Try all possible split points
            for k in range(i, j):
                # Cost of multiplying matrices i..k and k+1..j
                # Plus cost of multiplying the two resulting matrices
                cost = dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1]
                dp[i][j] = min(dp[i][j], cost)
    
    return dp[0][n - 1]

if __name__ == "__main__":
    n = int(input("Enter number of matrices: "))
    
    print("Enter dimensions array (n+1 values): ")
    p = list(map(int, input().split()))
    
    min_mult = matrix_chain_multiplication(p)
    print(f"Minimum number of multiplications: {min_mult}")
