# include<vector>
# include<algorithm>
using namespace std;

// 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
// 完全背包问题

class Solution {
public:
    vector<int> get_number(int n) {
        int i = 1;
        vector<int> nums;
        while(i*i <= n) {
            nums.push_back(i*i);
            i += 1;
        }
        return nums;
    }

    int numSquares(int n) {
        vector<int> nums = get_number(n);
        vector<int> dp(n+1, 10001);
        // dp[j] 的含义是和为j的最少数量
        // init dp
        for(int num: nums) {
            dp[num] = 1;
        }

        // 完全背包问题
        for (int i=0; i<nums.size(); i++) {
            for (int j=nums[i]; j<=n; j++) {
                dp[j] = min(dp[j], dp[j-nums[i]]+1);
            }
        }
        return dp[n];
    }
};