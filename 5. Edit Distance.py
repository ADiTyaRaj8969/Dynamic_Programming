# Task: Given two strings, word1 and word2, return the minimum number of operations (insert, delete, or substitute a character) required to convert word1 to word2.

# TC: O(m * n) where m and n are lengths of word1 and word2
# SC: O(m * n) for the DP table
def edit_distance(word1, word2):
    m, n = len(word1), len(word2)
    
    # dp[i][j] represents edit distance between word1[0..i-1] and word2[0..j-1]
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    # Base cases
    for i in range(m + 1):
        dp[i][0] = i  # Delete all characters from word1
    for j in range(n + 1):
        dp[0][j] = j  # Insert all characters to word1
    
    # Fill the DP table
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if word1[i - 1] == word2[j - 1]:
                # Characters match, no operation needed
                dp[i][j] = dp[i - 1][j - 1]
            else:
                # Minimum of insert, delete, or substitute
                dp[i][j] = 1 + min(
                    dp[i - 1][j],     # Delete from word1
                    dp[i][j - 1],     # Insert to word1
                    dp[i - 1][j - 1]  # Substitute
                )
    
    return dp[m][n]

# Space Optimized Version
# TC: O(m * n)
# SC: O(n) - using only 1D array
def edit_distance_optimized(word1, word2):
    m, n = len(word1), len(word2)
    
    prev = list(range(n + 1))
    
    for i in range(1, m + 1):
        curr = [i] + [0] * n
        for j in range(1, n + 1):
            if word1[i - 1] == word2[j - 1]:
                curr[j] = prev[j - 1]
            else:
                curr[j] = 1 + min(prev[j], curr[j - 1], prev[j - 1])
        prev = curr
    
    return prev[n]

if __name__ == "__main__":
    word1 = input("Enter first word: ")
    word2 = input("Enter second word: ")
    
    distance = edit_distance_optimized(word1, word2)
    print(f"Minimum edit distance: {distance}")
