# include<vector>
using namespace std;

// 目标和

class Solution {
private:
    int ans=0;
public:
    void dfs(int startIdx, vector<int>& nums, int target, int sum) {
        if (startIdx>=nums.size()) {
            if (sum==target) ans += 1;
            return;
        }
        dfs(startIdx+1, nums, target, sum+nums[startIdx]);
        
        dfs(startIdx+1, nums, target, sum-nums[startIdx]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        dfs(0, nums, target, 0);
        return ans;
    }
};


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // left - right = target
        // left + right = sum
        // left = (target + sum) / 2
        // 动态规划的组合问题
        // 之前碰到的01背包是问背包中的最大价值
        // 而这是一个组合问题
        int sum = 0;
        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];
        }
        if (sum<target) return 0;
        if ((sum+target)%2!=0) return 0;

        sum = (sum + target) / 2;
        vector<int> dp(sum+1, 0);
        // 初始化为1
        dp[0] = 1;
        for (int i=0; i<nums.size(); i++) {
            for (int j=sum; j>=nums[i]; j--) {
                // 递推公式
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[sum];
    }
};