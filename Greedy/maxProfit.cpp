# include<vector>
using namespace std;

// 买卖股票的最佳时机
// 贪心解法
// 在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        for (int i=1; i<prices.size(); i++) {
            if (prices[i]>prices[i-1]) {
                result += (prices[i]-prices[i-1]);
            }
        }
        return result;
    }
};