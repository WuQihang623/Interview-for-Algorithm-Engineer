# include<vector>
# include <climits>
# include<algorithm>
using namespace std;

// 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
// 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
// 完全背包的组合问题

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp(amount+1, 10001);
        for (int coin: coins) {
            if (coin <= amount) dp[coin] = 1;
        }

        for (int i=0; i<coins.size(); i++) {
            for (int j=coins[i]; j<=amount; j++) {
                dp[j] = min(dp[j], dp[j-coins[i]]+1);
            }
        }
        if (dp[amount] != 10001) return dp[amount];
        return -1;
    }
};