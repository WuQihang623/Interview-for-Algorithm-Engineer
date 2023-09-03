# include<iostream>
using namespace std;

class MyNode{
public:
    int val;
    MyNode* next;
    MyNode(): val(0), next(nullptr) {};
    MyNode(int val): val(val), next(nullptr) {};
    MyNode(int val, MyNode* node): val(val), next(node) {};
};

class MyLinkedList {
private:
    MyNode* _DynamicHead = new MyNode(0);
    int len;
public:
    MyLinkedList() {
        len = 0;
    }
    
    // 获取index处的值
    int get(int index) {
        if(index>=0 && index<len){
            MyNode* cur_node = _DynamicHead;
            for (int i=0; i<index; i++){
                cur_node = cur_node->next;
        }
        return (cur_node->next)->val;
        }
        return -1;
    }
    
    // 添加头节点
    void addAtHead(int val) {
        // 如果有一个节点
        if (len>0){
            // 执行插入的操作
            MyNode* head = new MyNode(val, _DynamicHead->next);
            _DynamicHead->next = head;
        }
        else{
            MyNode* head = new MyNode(val);
            _DynamicHead->next = head;
        }
        len++;
    }
    
    // 添加尾节点
    void addAtTail(int val) {
        MyNode* cur_node = _DynamicHead;
        MyNode* tail = new MyNode(val);
        for (int i=0; i<len; i++){
            cur_node = cur_node->next;
        }
        cur_node->next = tail;
        len++;
    }
    

    void addAtIndex(int index, int val) {
        if (index>len || index<0) return ;
        if (index==len){
            addAtTail(val);
            return ;
        }
        MyNode* cur_node = _DynamicHead;
        for (int i=0; i<index; i++){
            cur_node = cur_node->next;
        }
        // 插入尾节点
        if (cur_node->next==nullptr){
            MyNode* tail = new MyNode(val);
            cur_node->next = tail;
        }
        else{
            MyNode* newNode = new MyNode(val, cur_node->next);
            cur_node->next = newNode;
        }
        len++;
    }
    

    void deleteAtIndex(int index) {
        if (index>=len || index<0) return ;
        MyNode* cur_node = _DynamicHead;
        for (int i=0; i<index; i++){
            cur_node = cur_node->next;
        }
        MyNode* deleteNode = cur_node->next;
        if (deleteNode->next==nullptr) cur_node->next=nullptr;
        else{
            cur_node->next = (cur_node->next)->next;
        }
        delete deleteNode;
        len--;
    }

    void print(){
        MyNode* cur_node = _DynamicHead->next;
        for (int i=0; i<len; i++){
            cout << cur_node->val << "  ";
            cur_node = cur_node->next;
        }
        cout << endl;
    }
};

int main(){
    MyLinkedList myLinkedList;
    // myLinkedList.addAtHead(7);
    // myLinkedList.addAtHead(2);
    // myLinkedList.addAtHead(1);
    // myLinkedList.addAtIndex(3, 0);
    // myLinkedList.deleteAtIndex(2);
    // myLinkedList.addAtHead(6);
    // myLinkedList.addAtTail(4);
    // cout << "第4个元素是" << myLinkedList.get(4) << endl;
    // myLinkedList.addAtHead(4);
    // myLinkedList.addAtIndex(5, 0);
    // myLinkedList.addAtHead(6);
    // myLinkedList.print();

    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2);
    myLinkedList.print();
    myLinkedList.deleteAtIndex(0);
    myLinkedList.print();
    return 0;
}
