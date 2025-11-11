// Task: You are given the weights and values of n items and a knapsack that can hold a maximum
// weight W. You cannot break an item. Determine the maximum total value you can put into the
// knapsack.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// TC: O(n * W) where n is number of items and W is knapsack capacity
// SC: O(n * W) for the DP table
int knapsack(int W, vector<int>& weights, vector<int>& values, int n)
{
    // Create DP table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build table dp[][] in bottom-up manner
    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (weights[i - 1] <= w)
            {
                // Max of including or excluding current item
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            }
            else
            {
                // Can't include current item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

// Space Optimized Version
// TC: O(n * W)
// SC: O(W) - using only 1D array
int knapsackOptimized(int W, vector<int>& weights, vector<int>& values, int n)
{
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++)
    {
        // Traverse from right to left to avoid overwriting
        for (int w = W; w >= weights[i]; w--)
        {
            dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
        }
    }

    return dp[W];
}

int main()
{
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    vector<int> weights(n), values(n);
    cout << "Enter weights: ";
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    int maxValue = knapsackOptimized(W, weights, values, n);
    cout << "Maximum value: " << maxValue << endl;

    return 0;
}
