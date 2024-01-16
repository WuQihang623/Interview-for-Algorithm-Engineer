# include <vector>
# include<string>
using namespace std;

// 一和零
// 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
// 请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for (string str: strs) {
            int zeroNum=0, oneNum=0;
            for (char c: str) {
                if (c=='0') zeroNum += 1;
                else oneNum += 1;
            }
            for (int i=m; i>=zeroNum; i--) {
                for (int j=n; j>=oneNum; j--) {
                    dp[i][j] = max(dp[i][j], dp[i-zeroNum][j-oneNum] + 1);
                }
            }
        }
        return dp[m][n];
    }
};