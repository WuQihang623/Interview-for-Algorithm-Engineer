# include <vector>
# include <string>
# include<algorithm>
# include<iostream>
# include <unordered_map>
using namespace std;

class Solution {
private:
    string res;
    int count = 0;
    vector<string> ans;
public:
    bool isValidate(const string& s){
        int num = stoi(s); 
        if (num > 255) return false;
        if (s.size() > 1 && s[0]=='0') return false;
        return true;
    }

    void dfs(int startIndex, const string& s){ 
        if (startIndex >= s.size() || count >= 4) return;
        for (int i=startIndex; i<s.size() && (i-startIndex) < 3; i++){
            string substring = s.substr(startIndex, i-startIndex+1);
            if (isValidate(substring)){
                substring += ".";
                res += substring;
                count ++;
            }
            else continue;
            if (i == s.size()-1 && count==4){
                ans.push_back(res.substr(0, res.size()-1));
            }
            dfs(i+1, s);
            res = res.substr(0, res.size()-substring.size());
            count --;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        dfs(0, s);
        return ans;
    }
};

int main(){
    Solution s;
    string str = "25525511135";
    s.restoreIpAddresses(str);
}