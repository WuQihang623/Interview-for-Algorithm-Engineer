// 有效的括号||
# include<string>
# include<stack>
# include<iostream>
# include<unordered_map>
using namespace std;

// class Solution {
// public:
//     bool isValid(string s) {
//         if (s.size()%2!=0) return false;
//         stack<char> st;
//         for (int i=0; i<s.size(); i++){
//             char c = s[i];
//             if (c=='(' || c=='{' || c=='[') st.push(c);
//             else{
//                 if (st.empty()) return false;
//                 int top = (int) st.top();
//                 if (((int) c - top) <= 2 && ((int) c - top) > 0) st.pop();
//                 else return false;
//             }
//         }
//         if (st.empty()) return true;
//         else return false;
//     }
// };

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }

        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> stk;
        for (char ch: s) {
            if (pairs.count(ch)) {
                if (stk.empty() || stk.top() != pairs[ch]) {
                    return false;
                }
                stk.pop();
            }
            else {
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};


int main(){
    string s = "){";
    Solution solution;
    solution.isValid(s);
}