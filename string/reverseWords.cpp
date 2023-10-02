# include<string>
# include<iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string result{};
        int start, end = 0;
        for (int i=0; i<s.size(); i++){
            if (s[i] == ' ' && s[i+1] != ' '){
                start = i+1;
            }
            else if (s[i] != ' ' && (s[i+1] == ' ' || i==(s.size()-1))){
                end = i+1;
                if (result.size()!=0) result = s.substr(start, (end-start)) + " " + result;
                else result = s.substr(start, (end-start)) + result;
            }
        }
        return result;
    }
};


int main(){
    string s = "the sky is blue";
    Solution solution;
    string results = solution.reverseWords(s);
    cout << results << endl;
}