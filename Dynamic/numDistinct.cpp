# include<vector>
# include<string>
using namespace std;

// 给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数

// 回溯法会超时
class Solution {
private:
    string path;
    int ans = 0;
public:
    void backtrack(int startIdx, const string& s, const string& t) {
        if (path.size() == t.size()) {
            if (path == t) ans += 1;
            return ;
        }
        for (int i=startIdx; i<s.size(); i++) {
            path += s[i];
            backtrack(i+1, s, t);
            path = path.substr(0, path.size()-1);
        }
    }
    int numDistinct(string s, string t) {
        backtrack(0, s, t);
        return ans;
    }
};

class Solution {
public:
    int numDistinct(string s, string t) {
        // dp[i][j] 表示t[j]之前的数组在s[i]之前出现的次数
        // 所以dp[1][0] 表示""在s[:1]之前出现的次数，即为1
        vector<vector<uint64_t>> dp (s.size()+1, vector<uint64_t> (t.size()+1, 0));
        // 初始化
        for (int i=0; i<=s.size(); i++) {
            dp[i][0] = 1;
        }
        for (int i=1; i<=s.size(); i++) {
            for (int j=1; j<=t.size(); j++) {
                if (s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[s.size()][t.size()];

    }
};