#include<string>
#include<iostream>
using namespace std;

int main() {
    string s = "ABCD";
    string ans = "A";
    cout << s << endl;
    int l=0, r=1;
    if (s[l]!=s[r]) {
        ans += s[l];
    }
    while(r<s.size()) {
        if (s[l]!=s[r]) {
            ans +=s[r];
            r++;
            l=r-1;
        }
        else {
            r++;
            l++;
        }
    }
    cout << ans << endl;
    return 0;
}
