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