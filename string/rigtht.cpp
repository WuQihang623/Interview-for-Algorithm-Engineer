#include<iostream>
#include<string>
using namespace std;

// 右旋字符串

int main() {
    string s;
    int k;
    cin >> k;
    cin >> s;
    string right_str = s.substr(s.size()-k, k);
    for (int i=s.size()-k-1; i>=0; i--) {
        s[i+k] = s[i];
    }
    for (int i=0; i<k; i++) {
        s[i] = right_str[i];
    }
    cout << s;
    return 0;
}
