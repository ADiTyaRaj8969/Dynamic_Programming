// Task: Given two strings, text1 and text2, find and return their longest common subsequence as a
// new string. If there are multiple solutions, any one will suffice.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// TC: O(m * n) where m and n are lengths of text1 and text2
// SC: O(m * n) for the DP table
string longestCommonSubsequence(string text1, string text2)
{
    int m = text1.length();
    int n = text2.length();

    // Create DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Backtrack to find the LCS string
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            lcs = text1[i - 1] + lcs;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    return lcs;
}

int main()
{
    string text1, text2;
    cout << "Enter first string: ";
    cin >> text1;
    cout << "Enter second string: ";
    cin >> text2;

    string result = longestCommonSubsequence(text1, text2);
    cout << "Longest Common Subsequence: " << result << endl;
    cout << "Length: " << result.length() << endl;

    return 0;
}