# include<vector>
using namespace std;

// 买卖股票的最佳时机含冷冻期
// 买入->（买入持有）->卖出->冷冻期->不持有

// 买入股票状态： 1. 前一天就持有股票 2.前一天是冻结期或前一天是保持股票卖出状态
// 卖出股票状态： 1. 前一天就卖出了股票 2.前一天是冻结期
// 今天就卖出股票： 昨天一定是买入股票状态
// 冻结期： 昨天卖出了股票

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int day = prices.size();
        vector<vector<int>> dp(day, vector<int> (4, 0));
        dp[0][0] = -prices[0];
        for (int i=1; i<day; i++) {
            dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][3])-prices[i]); // 买入状态
            dp[i][1] = max(dp[i-1][1], dp[i-1][3]); // 卖出状态
            dp[i][2] = dp[i-1][0] + prices[i];
            dp[i][3] = dp[i-1][2];
        }
        return max(dp[day-1][1], max(dp[day-1][2], dp[day-1][3]));
    }
};