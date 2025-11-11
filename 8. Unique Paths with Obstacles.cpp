/*Task: You are given an m x n integer grid where 0 represents an empty space and 1 represents an
 * obstacle. Find the number of unique paths a robot can take to travel from the top-left corner (0,
 * 0) to the bottom-right corner (m-1, n-1), moving only down or right.*/

#include <iostream>
#include <vector>
using namespace std;

// TC: O(m * n) where m is number of rows and n is number of columns
// SC: O(m * n) for the DP table
int uniquePathsWithObstacles(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();

    // If start or end is obstacle, no path exists
    if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
    {
        return 0;
    }

    // Create DP table
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;

    // Fill first column
    for (int i = 1; i < m; i++)
    {
        dp[i][0] = (grid[i][0] == 0 && dp[i - 1][0] == 1) ? 1 : 0;
    }

    // Fill first row
    for (int j = 1; j < n; j++)
    {
        dp[0][j] = (grid[0][j] == 0 && dp[0][j - 1] == 1) ? 1 : 0;
    }

    // Fill the rest of the table
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }

    return dp[m - 1][n - 1];
}

// Space Optimized Version
// TC: O(m * n)
// SC: O(n) - using only 1D array
int uniquePathsWithObstaclesOptimized(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();

    if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
    {
        return 0;
    }

    vector<int> dp(n, 0);
    dp[0] = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                dp[j] = 0;
            }
            else if (j > 0)
            {
                dp[j] += dp[j - 1];
            }
        }
    }

    return dp[n - 1];
}

int main()
{
    int m, n;
    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter grid (0 for empty, 1 for obstacle):" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int paths = uniquePathsWithObstaclesOptimized(grid);
    cout << "Number of unique paths: " << paths << endl;

    return 0;
}
