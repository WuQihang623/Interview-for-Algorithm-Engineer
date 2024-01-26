# include<vector>
# include<algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int> (2*k, 0));
        // 初始化dp数组
        for (int i=0; i<k; i++) {
            dp[0][2*i] = -prices[0];
        }
        for (int i=1; i<prices.size(); i++) {
            dp[i][0] = max(dp[i-1][0], -prices[i]);            // 买入或者不买
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]+prices[i]);  // 卖出或者不卖
            for (int j=1; j<k; j++) {
                dp[i][2*j] = max(dp[i-1][2*j-1]-prices[i], dp[i-1][2*j]);  // 买入或者不买
                dp[i][2*j+1] = max(dp[i-1][2*j]+prices[i], dp[i-1][2*j+1]);  // 卖出或者不卖
            }
        }
        return dp[prices.size()-1][2*k-1];
    }
};