# include<string>
# include<vector>
using namespace std;

// 回文子串

class Solution {
public:
    int countSubstrings(string s) {
        int ans=0;
        for (int i=0; i<s.size(); i++) {
            ans += expand(s, i, i, s.size());
            ans += expand(s, i, i+1, s.size());
        }
        return ans;
    }

    int expand(const string& s, int i, int j, int length) {
        int num = 0;
        while(i>=0 && j<length && s[i]==s[j]) {
            num += 1;
            i--;
            j++;
        }
        return num;
    }
};

// 动态规划方法解法
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp (s.size(), vector<bool> (s.size(), false));
        int num = 0;
        // 如果遍历顺序是i从0到n-1，那么递推公式为dp[i+1][j-1]
        for (int i=s.size()-1; i>=0; i--) {
            for (int j=i; j<s.size(); j++) {
                if (s[i]==s[j]) {
                    // 当i==j或者为aa,bb这种情况时
                    if (j-i<=1) {
                        num += 1;
                        dp[i][j] = true;
                    }
                    else if (dp[i+1][j-1]) {
                        num += 1;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return num;
    }
};