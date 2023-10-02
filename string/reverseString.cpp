# include<vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int size = s.size();
        for (int i=0; i<(int)(size/2); i++){
            char right = s[size-1-i];
            s[size-1-i] = s[i];
            s[i] = right;
        }
    }
};