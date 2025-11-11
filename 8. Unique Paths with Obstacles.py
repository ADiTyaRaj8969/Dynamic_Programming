"""Task: You are given an m x n integer grid where 0 represents an empty space and 1 represents an obstacle. Find the number of unique paths a robot can take to travel from the top-left corner (0, 0) to the bottom-right corner (m-1, n-1), moving only down or right."""

# TC: O(m * n) where m is number of rows and n is number of columns
# SC: O(m * n) for the DP table
def unique_paths_with_obstacles(grid):
    m = len(grid)
    n = len(grid[0])
    
    # If start or end is obstacle, no path exists
    if grid[0][0] == 1 or grid[m - 1][n - 1] == 1:
        return 0
    
    # Create DP table
    dp = [[0] * n for _ in range(m)]
    dp[0][0] = 1
    
    # Fill first column
    for i in range(1, m):
        dp[i][0] = 1 if grid[i][0] == 0 and dp[i - 1][0] == 1 else 0
    
    # Fill first row
    for j in range(1, n):
        dp[0][j] = 1 if grid[0][j] == 0 and dp[0][j - 1] == 1 else 0
    
    # Fill the rest of the table
    for i in range(1, m):
        for j in range(1, n):
            if grid[i][j] == 0:
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
    
    return dp[m - 1][n - 1]

# Space Optimized Version
# TC: O(m * n)
# SC: O(n) - using only 1D array
def unique_paths_with_obstacles_optimized(grid):
    m = len(grid)
    n = len(grid[0])
    
    if grid[0][0] == 1 or grid[m - 1][n - 1] == 1:
        return 0
    
    dp = [0] * n
    dp[0] = 1
    
    for i in range(m):
        for j in range(n):
            if grid[i][j] == 1:
                dp[j] = 0
            elif j > 0:
                dp[j] += dp[j - 1]
    
    return dp[n - 1]

if __name__ == "__main__":
    m = int(input("Enter number of rows: "))
    n = int(input("Enter number of columns: "))
    
    print("Enter grid (0 for empty, 1 for obstacle):")
    grid = []
    for i in range(m):
        row = list(map(int, input().split()))
        grid.append(row)
    
    paths = unique_paths_with_obstacles_optimized(grid)
    print(f"Number of unique paths: {paths}")
