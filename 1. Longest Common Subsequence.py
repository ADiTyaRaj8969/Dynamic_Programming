# Task: Given two strings, text1 and text2, find and return their longest common subsequence as a new string. If there are multiple solutions, any one will suffice.

# TC: O(m * n) where m and n are lengths of text1 and text2
# SC: O(m * n) for the DP table
def longest_common_subsequence(text1, text2):
    m, n = len(text1), len(text2)
    
    # Create DP table
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    # Fill the DP table
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if text1[i - 1] == text2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    
    # Backtrack to find the LCS string
    lcs = []
    i, j = m, n
    while i > 0 and j > 0:
        if text1[i - 1] == text2[j - 1]:
            lcs.append(text1[i - 1])
            i -= 1
            j -= 1
        elif dp[i - 1][j] > dp[i][j - 1]:
            i -= 1
        else:
            j -= 1
    
    return ''.join(reversed(lcs))

if __name__ == "__main__":
    text1 = input("Enter first string: ")
    text2 = input("Enter second string: ")
    
    result = longest_common_subsequence(text1, text2)
    print(f"Longest Common Subsequence: {result}")
    print(f"Length: {len(result)}")
