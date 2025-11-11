// Task: Given an array of coin denominations and a total amount, write a function to compute the
// fewest number of coins that you need to make up that amount. If the amount cannot be made up,
// return -1.

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// TC: O(amount * n) where n is number of coin denominations
// SC: O(amount) for the DP array
int coinChange(vector<int>& coins, int amount)
{
    // dp[i] represents minimum coins needed to make amount i
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;  // Base case: 0 coins needed for amount 0

    // For each amount from 1 to target
    for (int i = 1; i <= amount; i++)
    {
        // Try each coin denomination
        for (int coin : coins)
        {
            if (coin <= i && dp[i - coin] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
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

    int result = coinChange(coins, amount);
    if (result == -1)
    {
        cout << "Amount cannot be made up with given coins" << endl;
    }
    else
    {
        cout << "Minimum coins needed: " << result << endl;
    }

    return 0;
}
