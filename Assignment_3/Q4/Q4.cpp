class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,0));//Here dp[i][j] represents that can we match s(0 ... i) to p(0...j).
        dp[0][0]=1;//nothing in string and nothing in p
        //Base case of 1 st row which mean no string character
        for (int j = 1; j <= m; j++) {
            if (p[j - 1] == '*'){//This condition is very mandatory as it allows what if an alphabet or ? comes in p so now s cannot be written in terms of p as s is empty , so in the case where p[i]= * then in that case the p can be written in s only if all behind the i index is a star or we can say if dp[0][j-1] is true .
                dp[0][j] = dp[0][j - 1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1]||p[j-1]=='?'){//as now it matches we have to move diagonal(as characters match so if dp[i-1][j-1] is true this is also true)
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    dp[i][j]=(dp[i][j-1]||dp[i-1][j]);//Here two conditions can be possible either * matches empty space or either it matches one or more no .of characters so if either of these two is true we can match s(0...i) to p(0...j).And we cannot use if or else as it restricts the use of * as empty space in between.
                }
            }
        }
        return dp[n][m];
    }
};
