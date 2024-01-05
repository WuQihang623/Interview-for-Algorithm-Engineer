# include<vector>
using namespace std;
// 使用最小花费爬楼梯
// 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。
// 一旦你支付此费用，即可选择向上爬一个或者两个台阶。

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp (cost.size()+1);
        dp[0] = 0;
        dp[1] = 0;
        for (int i=2; i<=cost.size(); i++) {
            dp[i] = min((dp[i-1] + cost[i-1]), (dp[i-2] + cost[i-2]));
        }
        return dp[cost.size()];
    }
};
