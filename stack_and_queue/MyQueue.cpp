# include<stack>
using namespace std;
class MyQueue {
public:
    stack<int> out_stack {};
    stack<int> in_stack {};
    MyQueue() {
    }
    
    void push(int x) { // 将元素x推到队列的末尾
        in_stack.push(x);
    }
    
    int pop() { // 从队列的开头移除并返回元素
        int top_value = 0;
        int size = in_stack.size();
        for (int i=0; i<size; i++){
            int value = in_stack.top();
            in_stack.pop();
            if (i!=size-1){
                out_stack.push(value);
            }
            else top_value = value;
        }
        int size = out_stack.size();
        for (int i=0; i<size; i++){
            int value = out_stack.top();
            out_stack.pop();
            in_stack.push(value);
        }
        return top_value;
    }
    
    int peek() { // 返回队列开头的元素
        int top_value = 0;
        int size = in_stack.size();
        for (int i=0; i<size; i++){
            int value = in_stack.top();
            in_stack.pop();
            out_stack.push(value);
            top_value = value;
        }
        size = out_stack.size();
        for (int i=0; i<size; i++){
            int value = out_stack.top();
            out_stack.pop();
            in_stack.push(value);
        }
        return top_value;
    }
    
    bool empty() { //  如果队列为空，返回 true ；否则，返回 false
        if (in_stack.size() == 0) return true;
        else return false;
    }
};

int main(){
    MyQueue myQueue = MyQueue();
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    myQueue.peek(); // return 1
    myQueue.pop(); // return 1, queue is [2]
    myQueue.empty(); // return false
}