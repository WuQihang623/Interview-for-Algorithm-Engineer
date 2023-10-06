# include<string>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int size=1; size <= (int)(s.size()/2); size++){
            bool flag = true;
            if (s.size() % size == 0){
                string substr = s.substr(0, size);
                for (int i=size; i<s.size(); i=i+size){
                    string substr_ = s.substr(i, size);
                    if (substr != substr_){
                        flag = false;
                        break;
                    }
                }
                if (flag) return true;
            }
        }
        return false;
    }
};

int main(){
    string s = "abab";
    Solution solution;
    solution.repeatedSubstringPattern(s);
}