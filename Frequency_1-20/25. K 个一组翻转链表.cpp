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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* p = dummy;
        ListNode* pre = dummy;
        while(true){
            pre = p;
            ListNode* start = p->next;
            for(int i = 0 ; i < k;i++){
                p = p->next;
                if (p == nullptr){
                    ListNode* result = dummy->next;
                    delete dummy;
                    return result;
                }
            }

            ListNode* end = p;
            ListNode* next = end->next;
            end->next = nullptr;

            ListNode* q = reverse(start);

            pre->next = q;
            start->next = next;
            p = start;
        }
    }

    ListNode* reverse(ListNode* head){
        ListNode* dummy = new ListNode();

        ListNode* p = dummy;
        while(head != nullptr){
            ListNode* q = head->next;
            head->next = p->next;
            p->next = head;
            head = q;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};