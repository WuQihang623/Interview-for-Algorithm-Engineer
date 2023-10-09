#include <iostream>
#include <queue>
using namespace std;
int main() {
    // 创建一个整数类型的优先级队列，默认是最大堆
    priority_queue<int> pq;
    // 向队列插入元素
    pq.push(3);
    pq.push(1);
    pq.push(4);
    pq.push(1);
    pq.push(5);
    // 访问并输出顶部元素
    while(!pq.empty()){
        cout << "顶部元素: " << pq.top() << endl;
        pq.pop();
    }
    return 0;
}