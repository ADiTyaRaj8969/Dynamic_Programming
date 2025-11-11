# Task: Given an integer array nums, return the length of the longest strictly increasing subsequence.

from bisect import bisect_left

# DP Approach
# TC: O(n^2) where n is the size of nums
# SC: O(n) for the DP array
def longest_increasing_subsequence(nums):
    n = len(nums)
    if n == 0:
        return 0
    
    # dp[i] represents length of LIS ending at index i
    dp = [1] * n
    max_len = 1
    
    for i in range(1, n):
        for j in range(i):
            if nums[i] > nums[j]:
                dp[i] = max(dp[i], dp[j] + 1)
        max_len = max(max_len, dp[i])
    
    return max_len

# Binary Search Approach (Most Optimized)
# TC: O(n log n) where n is the size of nums
# SC: O(n) for the tails array
def longest_increasing_subsequence_optimized(nums):
    n = len(nums)
    if n == 0:
        return 0
    
    # tails[i] stores the smallest tail element for LIS of length i+1
    tails = []
    
    for num in nums:
        # Binary search for the position to insert/replace
        pos = bisect_left(tails, num)
        
        if pos == len(tails):
            tails.append(num)
        else:
            tails[pos] = num
    
    return len(tails)

if __name__ == "__main__":
    n = int(input("Enter number of elements: "))
    nums = list(map(int, input("Enter array elements: ").split()))
    
    lis_length = longest_increasing_subsequence_optimized(nums)
    print(f"Length of Longest Increasing Subsequence: {lis_length}")
