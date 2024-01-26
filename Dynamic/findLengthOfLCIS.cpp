# include<algorithm>
# include<vector>
using namespace std;

// 最长连续递增序列

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int ans = 1;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i]>nums[i-1]) dp[i] = dp[i-1] + 1;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};