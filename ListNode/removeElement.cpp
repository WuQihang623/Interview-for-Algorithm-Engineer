# include<iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 获取起始节点
        while(head != nullptr && head->val == val){  // 记得要判断head!=nullptr
            //需要释放掉被删除的节点
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        // 删除节点
        ListNode* next1 = head;

        while(next1 != nullptr && next1->next != nullptr){
            if ((next1->next)->val == val){
                ListNode* tmp = next1->next;
                next1->next = (next1->next)->next;
                delete tmp;
            }
            else next1 = next1->next;
        }
        return head;
    }

    // 虚拟head节点法
    // ListNode* removeElements(ListNode* head, int val){
    //     // 创建一个虚拟的头节点，这样的话就不需要单独对头节点进行处理
    //     // 因为链表总是通过上一个节点去控制下一个
    //     ListNode* virtual_head = new ListNode();
    //     virtual_head->next = head;
    //     ListNode* cur_node = virtual_head;
    //     while(cur_node!=nullptr && cur_node->next!=nullptr){
    //         if ((cur_node->next)->val != val){
    //             cur_node = cur_node->next;
    //         }
    //         else{
    //             ListNode* tmp = cur_node->next;
    //             cur_node->next = tmp->next;
    //             delete tmp;
    //         }
    //     }
    //     return virtual_head->next;
    // }
};


int main(){
    ListNode* head = new ListNode(5);
    ListNode* node1 = new ListNode(4);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(5);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    Solution s;
    head = s.removeElements(head, 5);
    ListNode* node = head;
    cout << node->val << endl;
    while(node->next != nullptr){
        cout << (node->next)->val << endl;
        node = node->next;
    }
    return 0;
}
