// Task: Given an array p[] which represents the dimensions of a chain of matrices (matrix A_i has
// dimension p[i-1] x p[i]), find the minimum number of scalar multiplications needed to multiply
// the chain.

#include <bits/stdc++.h>
int matrixChainMultiplication(vector<int>& p)
{
    int n = p.size() - 1;  // Number of matrices

    // dp[i][j] represents minimum multiplications for matrices from i to j
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // len is chain length
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            // Try all possible split points
            for (int k = i; k < j; k++)
            {
                // Cost of multiplying matrices i..k and k+1..j
                // Plus cost of multiplying the two resulting matrices
                int cost = dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> p(n + 1);
    cout << "Enter dimensions array (n+1 values): ";
    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }

    int minMult = matrixChainMultiplication(p);
    cout << "Minimum number of multiplications: " << minMult << endl;

    return 0;
}

// TC: O(n^3) where n is the number of matrices
// SC: O(n^2) for the DP table
