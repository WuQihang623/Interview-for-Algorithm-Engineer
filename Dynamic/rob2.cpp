# include<vector>
# include<algorithm>
using namespace std;

// 打家劫舍2
// 这个地方所有的房屋都围成一圈 
// 1. 考虑首元素，不考虑尾元素，2.考虑尾元素， 不考虑首元素

class Solution {
public:
    int dynamic(int startIdx, int endIdx, vector<int>& nums) {
        if (startIdx==endIdx) return nums[startIdx];
        vector<int> dp(nums.size(), 0);
        dp[startIdx] = nums[startIdx];
        dp[startIdx+1] = max(nums[startIdx], nums[startIdx+1]);
        for (int i=startIdx+2; i<=endIdx; i++) {
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[endIdx];
    }
    int rob(vector<int>& nums) {
        if (nums.size()==1) return nums[0];
        int ans1 = dynamic(0, nums.size()-2, nums);
        int ans2 = dynamic(1, nums.size()-1, nums);
        return max(ans1, ans2);
    }
};