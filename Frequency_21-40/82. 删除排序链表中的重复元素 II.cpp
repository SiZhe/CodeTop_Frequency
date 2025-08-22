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
    ListNode* deleteDuplicates(ListNode* head) {
        std::unordered_map<int,int> unmap{};
        ListNode* p = head;
        while (p != nullptr){
            unmap[p->val]++;
            p = p->next;
        }

        ListNode* dummy = new ListNode();
        ListNode* q = dummy;
        p = head;

        while (p != nullptr){
            if(unmap[p->val] == 1){
                q->next = p;
                q = q->next;
            }
            p = p->next;
        }

        q->next = nullptr;

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};