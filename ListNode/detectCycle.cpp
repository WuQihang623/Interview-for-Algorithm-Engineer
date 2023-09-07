# include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head==NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next!=NULL){
            // fast 走两步， slow走一步看看会不会相遇
            fast = fast->next;
            if (fast->next==NULL) break;
            fast = fast->next;
            slow = slow->next;
            // 相遇了，并且知道了相遇的位置
            if (fast==slow) break;
        }
        if (fast->next==NULL) return NULL;
        // 如果是环形链表，则从相遇点出发与从起点出发相遇的就是要的结果
        ListNode* _Dynamic = head;
        while(_Dynamic!=fast){
            _Dynamic = _Dynamic->next;
            fast = fast->next;
        }
        return fast;
    }
};