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
    // 用到了两次for循环，效率很低，可以参考双指针法
// int linkLen(ListNode* head){
//         ListNode* cur_node = head;
//         int len = 1;
//         while(cur_node->next!=nullptr){
//             cur_node = cur_node->next;
//             len++;
//         }
//         return len;
//     }
//     ListNode* reverseList(ListNode* head) {
//         if (head == nullptr) return nullptr;
//         ListNode* _DynamicHead = new ListNode();
//         ListNode* this_node = _DynamicHead;
//         int len = linkLen(head);
//         for (int i=(len-1); i>=0; i--){
//             ListNode* cur_node = head;
//             for (int j=0; j<i; j++){
//                 cur_node = cur_node->next;
//             }
//             this_node->next = cur_node;
//             this_node = cur_node;
//         }
//         head->next = nullptr;
//         return _DynamicHead->next;
//     }

public:
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* _Dynamic = new ListNode();
    //     ListNode* newHead = new ListNode();
    //     ListNode* cur_node = newHead;
    //     _Dynamic->next = head;
    //     while(_Dynamic->next!=nullptr){
    //         ListNode* this_node = _Dynamic;
    //         while((this_node->next)->next!=nullptr) this_node = this_node->next;
    //         cur_node->next = this_node->next;
    //         this_node->next = nullptr;
    //         cur_node = cur_node->next;
    //     }
    //     return newHead->next;
    // }


    // 双指针法
    // ListNode* reverseList(ListNode* head){
    //     ListNode* pre = nullptr;
    //     ListNode* cur = head;
    //     ListNode* tmp;
    //     while(cur){
    //         tmp = cur->next;
    //         cur->next = pre;
    //         pre = cur;
    //         cur = tmp;
    //     }
    //     return pre;
    // }

    // 递归法, 调用函数要消耗栈空间
    ListNode* reverse(ListNode* pre, ListNode* cur){
        if (cur==nullptr) return pre;
        ListNode* tmp = cur->next;
        cur->next = pre;
        return reverse(cur, tmp);
    }

    ListNode* reverseList(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* cur = head;
        return reverse(pre, cur);
    }

};

int main(){
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    Solution s;
    ListNode* head = s.reverseList(node1);

    while(head!=nullptr){
        cout << head->val << "  ";
        head = head->next;
    }
    return 0;
}