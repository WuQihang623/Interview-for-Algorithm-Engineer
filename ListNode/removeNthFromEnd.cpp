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
    // 暴力求解，算出这个节点在正向的哪个位置
    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     ListNode* _Dynamic = new ListNode(0, head);
    //     ListNode* cur = _Dynamic;
    //     int len = 0;
    //     while (cur->next!=nullptr){
    //         len++;
    //         cur = cur->next;
    //     }
    //     if (n>len) return head;
    //     cur = _Dynamic;
    //     for (int i=0; i<(len-n); i++) cur = cur->next;
    //     ListNode* tmp = cur->next;
    //     cur->next = tmp->next;
    //     delete tmp;
    //     return _Dynamic->next; 
    // }


    // 双指针法-->快慢指针
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* _Dynamic = new ListNode(0, head);
        ListNode* fast_pointer = _Dynamic;
        ListNode* slow_pointer = _Dynamic;
        int gap = 0;
        while(fast_pointer!=nullptr){
            if (gap < (n+1)){
                fast_pointer = fast_pointer->next;
                gap++;
            }
            else{
                fast_pointer = fast_pointer->next;
                slow_pointer = slow_pointer->next;
            }
        }
        if (gap==(n+1)){
        ListNode* tmp = slow_pointer->next;
        slow_pointer->next = tmp->next;
        delete tmp;
        }
        return _Dynamic->next;
    }

};

int main(){
    ListNode* node1 = new ListNode(0);
    ListNode* node2 = new ListNode(1);
    node1->next = node2;
    Solution s;
    ListNode* head = s.removeNthFromEnd(node1, 1);

    while(head!=nullptr){
        cout << head->val << "  ";
        head = head->next;
    }
    return 0;

}