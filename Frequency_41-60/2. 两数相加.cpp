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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode();
        ListNode* p = dummy;
        while (l1 != nullptr && l2 != nullptr){
            int sum = carry;
            sum += (l1->val + l2->val);

            if (sum >= 10){
                carry = 1;
                sum %= 10;
            }else{
                carry = 0;
            }

            ListNode* tmp = new ListNode(sum);
            p->next = tmp;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != nullptr){
            int sum = carry;
            sum += l1->val;

            if (sum >= 10){
                carry = 1;
                sum %= 10;
            }else{
                carry = 0;
            }

            ListNode* tmp = new ListNode(sum);
            p->next = tmp;
            p = p->next;
            l1 = l1->next;
        }

        while(l2 != nullptr){
            int sum = carry;
            sum += l2->val;

            if (sum >= 10){
                carry = 1;
                sum %= 10;
            }else{
                carry = 0;
            }

            ListNode* tmp = new ListNode(sum);
            p->next = tmp;
            p = p->next;
            l2 = l2->next;
        }

        if (carry == 1){
            ListNode* tmp = new ListNode(carry);
            carry = 0;
            p->next = tmp;
            p = p->next;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};