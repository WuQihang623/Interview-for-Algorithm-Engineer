# include<stack>
# include<string>
# include<vector>
# include<iostream>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int size = tokens.size();
        stack<int> st;
        for (int i=0; i<size; i++){
            string c = tokens[i];
            if (c == "+" || c == "/" || c == "*" || c == "-"){
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                int num;
                if (c == "+") num = num1 + num2;
                else if (c == "-") num = num2 - num1;
                else if (c == "*") num = num1 * num2;
                else num = num2 / num1;
                st.push(num);
            }
            else st.push(stoi(c));
        }
        return st.top();
    }
};

int main(){
    vector<string> v = {"4","13","5","/","+"};
    Solution s;
    int i = s.evalRPN(v);
    cout << i;
}