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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* pre = dummy;
        for(int i = 0 ; i < left - 1 ; i++){
            pre = pre->next;
        }

        ListNode* start = pre->next;
        ListNode* end = start;
        for (int i = 0 ; i < right - left; i++){
            end = end->next;
        }

        ListNode* nextList = end->next;
        end->next = nullptr;

        ListNode* q = reverse(start);

        pre->next = q;

        while (q->next != nullptr){
            q = q->next;
        }

        q->next = nextList;

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }

    ListNode* reverse(ListNode* node){
        ListNode* dummy = new ListNode();
        ListNode* p = dummy;

        while (node != nullptr){
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