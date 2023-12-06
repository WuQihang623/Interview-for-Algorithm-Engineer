# include <vector>
# include <string>
# include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<char, string> letter_map = {
        {'2', "abc"}, 
        {'3', "def"}, 
        {'4', "ghi"},
        {'5', "jkl"}, 
        {'6', "mno"}, 
        {'7', "qprs"}, 
        {'8', "tuv"}, 
        {'9', "wxyz"}
    };
    vector<string> ans;
    string res;
public:
    void backtracking(int start_index, string& digits){
        if (start_index >= digits.size()) {
            ans.push_back(res);
        }
        else{
            for (char c: letter_map[digits[start_index]]){
                res.push_back(c);
                backtracking(start_index+1, digits);
                res.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size()==0) return ans;
        backtracking(0, digits);
        return ans;
    }
};