#include<bits/stdc++.h>
using namespace std;
void lcs(string& s1, string& s2,int i,int j,vector<vector<int>>& dp,string curr,set<string>& result){
    if (i == 0 || j == 0) {// set used for result as it will directly arrange in lexi order
        reverse(curr.begin(), curr.end()); // so that the alphabets we inserted in curr was in opposite order so to get string we have to reverse
        result.insert(curr);
        return;
    }
    if (s1[i - 1] == s2[j - 1]) {
        lcs(s1, s2, i - 1, j - 1, dp, curr + s1[i - 1], result);//if the characters match off s1 and s2 then I will insert it into curr string
    }
    else{
        if (dp[i - 1][j] > dp[i][j - 1]) {
            lcs(s1, s2, i - 1, j, dp, curr, result);//from our dp table which we made earlier we can find is it better to go left or up when characters don't match
        }                                                  
        else if (dp[i - 1][j] < dp[i][j - 1]) {
            lcs(s1, s2, i, j - 1, dp, curr, result);
        } 
        else {//If both path in dp table have same value(means same length) we have to check both parts to get all lcs
            lcs(s1, s2, i - 1, j, dp, curr, result);
            lcs(s1, s2, i, j - 1, dp, curr, result);
        }
    }
}
int main(){
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int n=s1.length();
    int m=s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];//diagonal path if equal in 2 d dp table and base case initialised when we putr full dp table as 0 amd starting indexxing from 1
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);// either up or down we will choose the maximum one
        }
    }//Filling dp table by bottom up dp method 
    set<string> result;
    lcs(s1, s2, n, m, dp, "",result);
    for (const string& i: result) {
    cout << i << endl;
    }
    return 0;
}
