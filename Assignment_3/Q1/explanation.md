## Brief Explanation of Correct Code

In the correct version of the code, I am using recursion with memoization to find the longest common subsequence (LCS) between two strings.  
The base case checks if either index becomes negative (`n < 0 || m < 0`), and in that case, it returns 0.  
If the characters at the current positions match (`s1[n] == s2[m]`), it means that character is part of the LCS, so I add 1 and move diagonally to the previous characters.  
If they don’t match, I try both possibilities — moving left in one string or up in the other — and take the maximum of the two results.  
To avoid solving the same subproblems again and again, I store the results in a 2D `dp` table and reuse them when needed.

