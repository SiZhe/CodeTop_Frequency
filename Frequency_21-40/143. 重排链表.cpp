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
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }


        ListNode* first = head;
        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* q = reverse(second);

        ListNode* p = head;

        while (q != nullptr && p != nullptr){
            ListNode* f = p->next;
            ListNode* s = q->next;
            p->next = q;
            q->next = f;
            p = f;
            q = s;
        }
    }

    ListNode* reverse(ListNode* node){
        ListNode* dummy = new ListNode();
        ListNode* p = dummy;

        while(node != nullptr){
            ListNode* q = node->next;

            node->next = p->next;
            p->next = node;

            node = q;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};