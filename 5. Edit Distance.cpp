// Task: Given two strings, word1 and word2, return the minimum number of operations (insert,
// delete, or substitute a character) required to convert word1 to word2.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// TC: O(m * n) where m and n are lengths of word1 and word2
// SC: O(m * n) for the DP table
int editDistance(string word1, string word2)
{
    int m = word1.length();
    int n = word2.length();

    // dp[i][j] represents edit distance between word1[0..i-1] and word2[0..j-1]
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Base cases
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = i;  // Delete all characters from word1
    }
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = j;  // Insert all characters to word1
    }

    // Fill the DP table
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                // Characters match, no operation needed
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                // Minimum of insert, delete, or substitute
                dp[i][j] = 1 + min({
                                   dp[i - 1][j],     // Delete from word1
                                   dp[i][j - 1],     // Insert to word1
                                   dp[i - 1][j - 1]  // Substitute
                               });
            }
        }
    }

    return dp[m][n];
}

// Space Optimized Version
// TC: O(m * n)
// SC: O(n) - using only 1D array
int editDistanceOptimized(string word1, string word2)
{
    int m = word1.length();
    int n = word2.length();

    vector<int> prev(n + 1), curr(n + 1);

    // Initialize base case
    for (int j = 0; j <= n; j++)
    {
        prev[j] = j;
    }

    for (int i = 1; i <= m; i++)
    {
        curr[0] = i;
        for (int j = 1; j <= n; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                curr[j] = prev[j - 1];
            }
            else
            {
                curr[j] = 1 + min({prev[j], curr[j - 1], prev[j - 1]});
            }
        }
        prev = curr;
    }

    return prev[n];
}

int main()
{
    string word1, word2;
    cout << "Enter first word: ";
    cin >> word1;
    cout << "Enter second word: ";
    cin >> word2;

    int distance = editDistanceOptimized(word1, word2);
    cout << "Minimum edit distance: " << distance << endl;

    return 0;
}
