/*Task: Given an array of coin denominations and a total amount, write a function to compute the
 * total number of distinct combinations of coins that make up that amount. Assume an infinite
 * supply of each coin.*/

#include <iostream>
#include <vector>
using namespace std;

// TC: O(amount * n) where n is number of coin denominations
// SC: O(amount) for the DP array
int coinChangeWays(vector<int>& coins, int amount)
{
    // dp[i] represents number of ways to make amount i
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;  // Base case: 1 way to make amount 0 (use no coins)

    // For each coin denomination
    for (int coin : coins)
    {
        // Update all amounts that can be made with this coin
        for (int i = coin; i <= amount; i++)
        {
            dp[i] += dp[i - coin];
        }
    }

    return dp[amount];
}

// 2D DP Approach (for better understanding)
// TC: O(amount * n)
// SC: O(amount * n)
int coinChangeWays2D(vector<int>& coins, int amount)
{
    int n = coins.size();

    // dp[i][j] = ways to make amount j using first i coins
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

    // Base case: 1 way to make amount 0
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            // Don't use current coin
            dp[i][j] = dp[i - 1][j];

            // Use current coin (if possible)
            if (coins[i - 1] <= j)
            {
                dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
    }

    return dp[n][amount];
}

int main()
{
    int n, amount;
    cout << "Enter number of coin denominations: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    cout << "Enter target amount: ";
    cin >> amount;

    int ways = coinChangeWays(coins, amount);
    cout << "Number of ways to make change: " << ways << endl;

    return 0;
}
