#include "../core.hpp"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ha = headA;
        ListNode* hb = headB;
        int na {0};
        int nb {0};
        while (ha != nullptr || hb != nullptr){
            if (ha != nullptr ){
                ha = ha->next;
                na++;
            }
            if (hb != nullptr){
                hb = hb->next;
                nb++;
            }
        }

        ha = headA;
        hb = headB;
        int t = std::abs(na - nb);

        if (na >= nb){
            for (int i = 0 ; i < t ; i++){
                ha = ha->next;
            }
        }else{
            for (int i = 0 ; i < t ; i++){
                hb = hb->next;
            }
        }

        while (ha != nullptr){
            if (ha == hb){
                return ha;
            }
            ha = ha->next;
            hb = hb->next;
        }

        return nullptr;
    }
};