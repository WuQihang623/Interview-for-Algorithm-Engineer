#include<vector>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // 全排列问题
        // 如果是要求出排列，那么必须要用回溯
        // 全排列问题先遍历背包，再遍历物品
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int j=1; j<=target; j++) {
            for (int i=0; i<nums.size(); i++) {
                if (j>=nums[i] && dp[j]<INT_MAX-dp[j-nums[i]]) dp[j] += dp[j-nums[i]];
            }
        }
        return dp[target];
    }
};