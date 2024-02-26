# include<vector>
# include<string>
# include<algorithm>
using namespace std;

// 划分字母区间

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        vector<int> hash (26, 0); // 字符出现的最后一个下标
        for(int i=0; i<s.size(); i++) {
            hash[int(s[i]-'a')] = i;
        }
        
        int left = 0;
        int right = 0;
        for (int i=0; i<s.size(); i++) {
            right = max(right, hash[int(s[i]-'a')]);
            if (right==i) {
                ans.push_back(right-left+1);
                left = i + 1;
            }
        }
        return ans;
    }
};