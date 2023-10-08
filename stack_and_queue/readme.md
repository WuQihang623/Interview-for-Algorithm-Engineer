# 用栈实现队列MyQueue.cpp
![Alt text](fig/myqueue.png)
## STL中栈的操作
```cpp
# include<stack>
stack<int> q;
q.push(1); //使元素入栈，时间复杂度O(1)
q.top(); //查询栈顶， 时间复杂度O(1)
q.pop(); //删除栈顶元素
q.empty(); //检验是否为空
q.size(); //查询栈内元素个数， 时间复杂度O(1)
```
# 用队列实现栈
![Alt text](fig/myqueue.png)
## STL中队列的操作
```cpp
#include<queue>
queue<int> myQueue;
myQueue.push(10); //将元素插入队列的尾部
int element = myQueue.front(); // 访问队列的首元素
myQueue.pop(); //删除队列的首元素
myQueue.empty(); //检查队列是否为空
int size = myQueue.size(); //获取队列中元素的数量
```

# 有效的括号isValid.cpp
![Alt text](fig/isvalid.png)
