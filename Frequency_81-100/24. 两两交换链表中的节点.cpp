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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr){
            return head;
        }

        ListNode* dummy = new ListNode();
        ListNode* q = dummy;
        ListNode* p = head;
        while (p != nullptr && p->next != nullptr){
            ListNode* next = p->next;

            ListNode* nextT = next->next;

            q->next = next;
            q = q->next;
            q->next = p;
            q = q->next;

            p = nextT;
        }

        q->next = p;

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};