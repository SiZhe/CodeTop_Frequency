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
        std::map<int,int> map{};
        ListNode* dummy = new ListNode();
        ListNode* p = head;
        ListNode* q = dummy;

        while(p != nullptr){
            map[p->val]++;

            if (map[p->val] == 1){
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