# include<vector>
using namespace std;

// 不相交的线

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // 本题求解的就是最长的公共子序列的长度
        // dp[i][j]表示下标i与下标j之前的最大子序列长度
        vector<vector<int>> dp(nums1.size()+1, vector<int> (nums2.size()+1, 0));
        for (int i=1; i<=nums1.size(); i++) {
            for (int j=1; j<=nums2.size(); j++) {
                if (nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[nums1.size()][nums2.size()];

    }
};