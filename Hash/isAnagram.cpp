# include<string>
# include<iostream>
using namespace std;

class Solution {
public:
    void statistics(const string& s, int* char_list){
        int size = s.size();
        for (int i=0; i<size; i++) char_list[int(s[i])]++;
    }
    bool isAnagram(string s, string t) {
        int char_num_s[256]{};
        int char_num_t[256]{};
        statistics(s, char_num_s);
        statistics(t, char_num_t);
        for (int i=0; i<256; i++){
            if (char_num_s[i]!=char_num_t[i]) return false;
        }
        return true;
    }
};


int main(){
    string s = "wuqihang";
    for (int i=0; i<s.size(); i++){
        cout << int(s[i]) << endl;
    }
    return 0;
}