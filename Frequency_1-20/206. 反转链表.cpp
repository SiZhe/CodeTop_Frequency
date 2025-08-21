#include "../core.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 先向上指 再向下指
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = new ListNode();
        ListNode* p = dummy;
        ListNode* head1 = head;
        while(head1 != nullptr){
            ListNode* q = head1->next;
            head1->next = p->next;
            p->next = head1;
            head1 = q;
        }
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};