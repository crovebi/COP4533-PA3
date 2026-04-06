# COP4533-PA3
Programming Assignment 3: Highest Value Longest Common Sequence by Sebastian Crovetto (51487318) & Mosimiloluwa Ajani (79157785)

## Instructions for Completion

# Question 1: Empirical Comparison

# Question 2: Recurrence Equation
Let strings A and B be given. Let v(c) be the value of character c from the alphabet.
- dp[i][j] = max value of a common subsequence of the first i characters of A and first j characters of B

Base Cases
- dp[i][0] = 0 for all i >= 0
- dp[0][j] = 0 for all j >= 0

Recurrence

dp[i][j] = 
- dp[i-1][j-1] + v(A[i-1]), dp[i-1][j], dp[i][j-1] if A[i-1] == B[j-1]
- max(dp[i-1][j], dp[i][j-1]) if A[i-1] != B[j-1]

If the current characters match, include their values and add to the optimal solution for the previous prefixes. If they dont, take the maximum value by going over one character from either string.

Explanation
- This works because with HVCLS, the optimal subsequence of A[0...i-1] and B[0..j-1] depends only on the optimal solutions of smaller prefixes. By always taking the maximum value at each step, dp[i][j] correct computes the maximum total value of any common subsequence.

# Question 3: Big-Oh
Pseudocode

HVLCS(string A, string B, characterVal)

    n = length(A)
    m = length(B)
    
    create table of max values (implemented as vector in main code)
    dp = array of size (n+1) x (m+1)

    for i = 0 to n:
        for j = 0 to m:
            if i == 0 or j == 0:
                dp[i][j] = 0
            else if A[i-1] == B[j-1]:
                dp[i][j] = dp[i-1][j-1] + v(A[i-1])
            else:
                dp[i][j] = max(dp[i-1][j], dp[i][j-1])
    return dp[n][m]

Runtime
- The algorithm creates a 2D table (n+1) x (m+1), with each cell storing an integer. There are n x m cells and to fill each one, it takes O(1) time. The total runtime is O(n x m).
