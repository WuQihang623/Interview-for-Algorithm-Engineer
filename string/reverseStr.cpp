# include<string>
using namespace std;

class Solution {
public:
    void reverse(string& s, int start, int end){
        while(start < end){
            char tmp = s[end];
            s[end] = s[start];
            s[start] = tmp;
            start++;
            end--;
        }
    }
    string reverseStr(string s, int k) {
        int size = s.size();
        int i=0;
        while(i*k<size){
            if (i%2==0){
                int start = i*k;
                int end = (i+1)*k-1;
                if (end > size-1) end = size - 1;
                reverse(s, start, end);
            }
            i++;
        }
        return s;
    }
};