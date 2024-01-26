# include<vector>
using namespace std;

// 回溯法超时
class Solution {
private:
    int length = 1;
    vector<int> path;
public:
    void backtrack(int startIdx, vector<int>& nums) {
        if (startIdx>=nums.size()) {
            length = max(length, (int) path.size());
            return;
        }
        for (int i=startIdx; i<nums.size(); i++) {
            if (path.size() != 0) {
                if (nums[i]<=path[path.size()-1]) {
                    backtrack(i+1, nums);
                    continue;
                }
            }
            path.push_back(nums[i]);
            backtrack(i+1, nums);
            path.pop_back();
        }
    }

    int lengthOfLIS(vector<int>& nums) {
        backtrack(0, nums);
        return length;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int ans = 1;
        // dp[i]表示i之前包括i的以nums[i]结尾的最长递增子序列的长度
        vector<int> dp(nums.size(), 1);
        for (int i=1; i<nums.size(); i++) {
            for (int j=0; j<i; j++) {
                if (nums[i]>nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};