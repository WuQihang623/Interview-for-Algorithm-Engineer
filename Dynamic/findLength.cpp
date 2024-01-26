# include<vector>
using namespace std;

// 最长重复子数组

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size()==0 || nums2.size()==0) return 0;
        int ans = 0;
        // dp[i][j] 表示已 i和j结尾的数组的最长子数组长度
        vector<vector<int>> dp(nums1.size()+1, vector<int> (nums2.size()+1,0));
        for (int i=1; i<=nums1.size(); i++) {
            for (int j=1; j<=nums2.size(); j++) {
                if (nums1[i-1]==nums2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};