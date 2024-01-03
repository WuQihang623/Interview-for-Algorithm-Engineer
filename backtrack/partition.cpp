# include <vector>
# include <string>
# include<algorithm>
# include <unordered_map>
using namespace std;

class Solution {
private:
    vector<vector<string>> ans;
    vector<string> res;
public:
    // 判断是否为回文
    bool isPalindrome(const string& s, int start, int end){
        while(start < end){
            if (s[start] != s[end]) return false;
            start ++;
            end --;
        }
        return true;
    }

    void dfs(int startIndex, const string& s){
        // 当startIndex
        if (startIndex >= s.size()) {
            ans.push_back(res);
            return ;
        }

        for (int i=startIndex; i<s.size(); i++){
            // 是回文，则添加到res中
            if (isPalindrome(s, startIndex, i)){
                string sub_string = s.substr(startIndex, i-startIndex+1); // substr的参数是开头的索引以及字符的长度
                res.push_back(sub_string);
            }
            // 不是回文的话就跳过
            else continue;

            dfs(i+1, s);
            res.pop_back(); //弹出添加进去的子串
        }
    }

    vector<vector<string>> partition(string s) {
        dfs(0, s);
        return ans;
    }
};