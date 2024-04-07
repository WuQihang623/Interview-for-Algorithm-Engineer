#include<iostream>
using namespace std;

int main() {
    int n=10;
    int count=0;
    while(n>=3) {
        int n1 = n/3*3;  // 喝的数量
        count += n1;
        cout << count << endl;
        n = n - n1 +  n1 / 3;  // 换到酒的数量
        
    }
    count += n;
    cout << count << endl;
}