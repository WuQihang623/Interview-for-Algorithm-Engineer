# include<vector>
using namespace std;

// 整数拆分
// 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n ; i++) {
            for (int j = 1; j <= i / 2; j++) {
                // 递推公式， dp[i-j] * j ， 不是 dp[j] * (i-j), 因为你是拆分成 x + j
                dp[i] = max(dp[i], max((i - j) * j, dp[i-j] * j)); 
            }
        }
        return dp[n];
    }
};