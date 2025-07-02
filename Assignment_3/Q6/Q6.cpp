class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<int>>dp(n,vector<int>(3,0));//n*3 dp to ensure three possibility at index is sell ,hold,rest(cooldown) the maxprofit if we use one of the three way
        dp[0][0] = -prices[0];//Hold case basicalluy it consider the case of buying so we spent so negative profit
        dp[0][1] = 0;//if sold but we have nothing to sell so no profit
        dp[0][2] = 0;//if rest means we have just sell on previous one or just doing nothing
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);//for hold two options either u are holding from previous index or u just bought it on this index.
            dp[i][1] = dp[i - 1][0] + prices[i];//for selling we will add hold + current price to get buy impact as we have to buy first to sell means we have to buy or hold at previous indices
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);//for resting means either we're just resting from previous index or we just sell on previous index
        }
        return max(dp[n - 1][1], dp[n - 1][2]); // Final profit can't be in "hold" state
    }
};
