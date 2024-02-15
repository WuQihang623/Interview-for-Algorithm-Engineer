# include<string>
using namespace std;

// 单调递增的数组

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int flag = s.size();
        for (int i=s.size()-2; i>=0; i--) {
            if (s[i] > s[i+1]) {
                s[i]--;
                flag = i+1;
            }
        }
        for (int i=flag; i<s.size(); i++) {
            s[i] = '9';
        }
        return stoi(s);
    }
};