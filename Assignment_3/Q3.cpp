class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
      //Finding longest palindromic subsequence length
        //dp[i][j] is the length of longest palindromic subsequence from index i to index j
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base case as every single character is a palindrome
        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;

        // Fill the DP table we can observe that in case of match dp[i][j] depends on dp[i+1][j-1] so this give us idea to start dp table from end 
      //as otherwise if we start from start then we have uninitialised dp values for finding current values
        for (int i=n-1; i >= 0; i--) {
            for (int j = i+1; j<n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j]=2+dp[i+1][j-1];//if charcter matches then  forward index should be brought 1 ahead and backward 1 behind
                } 
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);//if not match it's our option either to increase starting index or decrease last index
                }
            }
        }

        // Minimum insertions = total length - Longest palindromic subsequence
        return n - dp[0][n - 1];
    }
};
