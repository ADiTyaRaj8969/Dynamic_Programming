// Task: Given an integer array nums, return the length of the longest strictly increasing
// subsequence.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// DP Approach
// TC: O(n^2) where n is the size of nums
// SC: O(n) for the DP array
int longestIncreasingSubsequence(vector<int>& nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    // dp[i] represents length of LIS ending at index i
    vector<int> dp(n, 1);
    int maxLen = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLen = max(maxLen, dp[i]);
    }

    return maxLen;
}

// Binary Search Approach (Most Optimized)
// TC: O(n log n) where n is the size of nums
// SC: O(n) for the tails array
int longestIncreasingSubsequenceOptimized(vector<int>& nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    // tails[i] stores the smallest tail element for LIS of length i+1
    vector<int> tails;

    for (int num : nums)
    {
        // Binary search for the position to insert/replace
        auto it = lower_bound(tails.begin(), tails.end(), num);

        if (it == tails.end())
        {
            tails.push_back(num);
        }
        else
        {
            *it = num;
        }
    }

    return tails.size();
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    int lisLength = longestIncreasingSubsequenceOptimized(nums);
    cout << "Length of Longest Increasing Subsequence: " << lisLength << endl;

    return 0;
}
