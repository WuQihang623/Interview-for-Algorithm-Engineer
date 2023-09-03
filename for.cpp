# include<iostream>
using namespace std;

int main(){
    for (int i=0; i < -1; i++){ // 如果一开始的条件不符合，就不会进入循环
        cout << i << endl;
    }
    return 0;
}

