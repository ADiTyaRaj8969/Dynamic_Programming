/*Task: Write a function that takes two integers n and k and returns the binomial coefficient $C(n,
 * k)$ using a dynamic programming approach. Handle potential overflows if necessary.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC: O(n * k) where n and k are the input parameters
// SC: O(n * k) for the DP table
long long binomialCoefficient(int n, int k)
{
    // Create DP table
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));

    // Base cases
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;  // C(i, 0) = 1
        if (i <= k)
        {
            dp[i][i] = 1;  // C(i, i) = 1
        }
    }

    // Fill the table using Pascal's identity: C(n, k) = C(n-1, k-1) + C(n-1, k)
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= min(i - 1, k); j++)
        {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp[n][k];
}

// Space Optimized Version
// TC: O(n * k)
// SC: O(k) - using only 1D array
long long binomialCoefficientOptimized(int n, int k)
{
    // Optimize by using symmetry property: C(n, k) = C(n, n-k)
    if (k > n - k)
    {
        k = n - k;
    }

    vector<long long> dp(k + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        // Traverse from right to left to avoid overwriting
        for (int j = min(i, k); j > 0; j--)
        {
            dp[j] = dp[j] + dp[j - 1];
        }
    }

    return dp[k];
}

int main()
{
    int n, k;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;

    if (k > n || k < 0 || n < 0)
    {
        cout << "Invalid input! k should be between 0 and n." << endl;
        return 1;
    }

    long long result = binomialCoefficientOptimized(n, k);
    cout << "C(" << n << ", " << k << ") = " << result << endl;

    return 0;
}
