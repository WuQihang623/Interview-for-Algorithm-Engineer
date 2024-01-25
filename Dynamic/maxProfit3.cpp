# include<vector>
# include<algorithm>
using namespace std;

// 买卖股票的最佳时机3
// 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // dp[i][j] 表示在第i天执行j操作得收益
        vector<vector<int>> dp(prices.size(), vector<int> (5, 0));
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];
        for (int i=1; i<prices.size(); i++) {
            dp[i][1] = max(dp[i-1][1], -prices[i]);
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
            dp[i][3] = max(dp[i-1][3], dp[i-1][2]-prices[i]);
            dp[i][4] = max(dp[i-1][4], dp[i-1][3]+prices[i]);
        }
        return dp[prices.size()-1][4];
    }
};