# include<string>
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