# include<iostream>
using namespace std;


// 定义单链表
class ListNode{
public:
    int val; //节点存放的数据
    ListNode *next; //指向下一个节点的指针
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}  // nullptr，是c++中空指针类型的关键字
    int get_val(){
        return val;
    }
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 获取起始节点
        while(head != nullptr && head->val == val){
            head = head->next;
        }
        // 删除节点
        ListNode* next1 = new ListNode();
        if ((head->next)->val == val) next1 = (head->next)->next;
        else next1 = head->next;
        while(next1 != nullptr && next1->next != nullptr){
            if ((next1->next)->val == val){
                next1->next = (next1->next)->next;
            }
            next1 = next1->next;
        }
        return head;
    }
};


int main(){
    // 初始化
    ListNode* head = new ListNode(5);  // 指针类型初始化要么用new，要么赋值nullptr，要么指向一个对象
    cout << head->get_val() << endl;
    delete head;
}
