# include<vector>
using namespace std;

// 分割子集问题

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) return false;
        vector<vector<int>>  dp(nums.size(), vector<int>(sum/2+1, 0));
        for (int j=nums[0]; j<=sum/2; j++) dp[0][j] = nums[0];
        for (int i=1; i<nums.size(); i++) {
            for (int j=1; j<=sum/2; j++) {
                if(j>=nums[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i]]+nums[i]);
                else dp[i][j] = dp[i-1][j];
            }
        }
        if (dp[nums.size()-1][sum/2]==sum/2) return true;
        else return false;
    }
};