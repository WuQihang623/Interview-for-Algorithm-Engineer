# include<vector>
# include<string>
using namespace std;

// 两个字符串的相减操作

// 方法1
class Solution {
public:
    int minDistance(string word1, string word2) {
        // 最大子序列
        // dp[i][j]：长度为[0, i - 1]的字符串text1与长度为[0, j - 1]的字符串text2的最长公共子序列为dp[i][j]
        vector<vector<int>> dp(word1.size()+1, vector<int> (word2.size()+1, 0));
        for (int i=1; i<=word1.size(); i++) {
            for (int j=1; j<=word2.size(); j++) {
                if (word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return word1.size()-dp[word1.size()][word2.size()] + word2.size()-dp[word1.size()][word2.size()];
    }
};

// 方法2
class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j]表示要删除的最小操作数
        // 那么初始化时dp[i][0] = i, dp[0][j]=j
        vector<vector<int>> dp(word1.size()+1, vector<int> (word2.size()+1, 0));
        for (int i=1; i<=word1.size(); i++) dp[i][0] = i;
        for (int j=1; j<=word2.size(); j++) dp[0][j] = j;

        for (int i=1; i<=word1.size(); i++) {
            for (int j=1; j<=word2.size(); j++) {
                if (word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + 1;
            }
        }    
        return dp[word1.size()][word2.size()];
    }
};