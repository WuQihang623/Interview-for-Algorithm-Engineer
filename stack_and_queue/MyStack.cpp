# include<queue>
using namespace std;
// 使用两个queue来实现栈
// class MyStack {
// queue<int> in_q;
// queue<int> out_q;
// public:
//     MyStack() {

//     }
//     // 将元素 x 压入栈顶。
//     void push(int x) {
//         in_q.push(x);
//     }
//     // 移除并返回栈顶元素。
//     int pop() {
//         // 将in_q中的元素转到out_q中
//         int size = in_q.size();
//         for (int i=0; i<size-1; i++){
//             out_q.push(in_q.front());
//             in_q.pop();
//         }
//         int top_value = in_q.front();
//         in_q.pop();
//         size = out_q.size();
//         // 将out_q中的元素转到in_q
//         for (int i=0; i<size; i++){
//             in_q.push(out_q.front());
//             out_q.pop();
//         }
//         return top_value;
//     }
//     // 返回栈顶元素。
//     int top() {
//         int top_value = this->pop();
//         push(top_value);
//         return top_value;
//     }
//     //如果栈是空的，返回 true ；否则，返回 false 。
//     bool empty() {
//         return in_q.empty();
//     }
// };

//使用一个队列来实现栈
class MyStack {
private:
    queue<int> que;
public:
    MyStack(){

    }
    // 将元素 x 压入栈顶。
    void push(int x) {
        que.push(x);
    }
    // 移除并返回栈顶元素。
    int pop() {
        int pop_time = que.size()-1;
        while(pop_time--){
            que.push(que.front());
            que.pop();
        }
        int top_value = que.front();
        que.pop();
        return top_value;
    }
    // 返回栈顶元素。
    int top() {
        int top_value = this->pop();
        push(top_value);
        return top_value;
    }
    bool empty() {
        return que.empty();
    }
};