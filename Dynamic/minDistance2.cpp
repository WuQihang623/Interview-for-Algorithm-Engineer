# include<vector>
# include<string>
using namespace std;

// 编辑距离

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int> (word2.size()+1, 0));
        for (int i=1; i<=word1.size(); i++) dp[i][0] = i;
        for (int j=1; j<=word2.size(); j++) dp[0][j] = j;

        for (int i=1; i<=word1.size(); i++) {
            for (int j=1; j<=word2.size(); j++) {
                // 不用操作
                if (word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1];
                // 增加或删除或替换, 其中，增加与删除的操作是一样的
                else dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+1);
            }
        }
        return dp[word1.size()][word2.size()];
    }
};