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

#if 0
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }

    ListNode* mergeSort(ListNode* head){
        if (head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* midpre = midPre(head);
        ListNode* mid = midpre->next;
        midpre->next = nullptr;
        ListNode* l = mergeSort(head);
        ListNode* r = mergeSort(mid);

        return merge(l,r);
    }

    ListNode* merge(ListNode* node1, ListNode* node2){
        ListNode* dummy = new ListNode();
        ListNode* p = dummy;
        while (node1 != nullptr && node2 != nullptr){
            if (node1->val <= node2->val){
                p->next = node1;
                node1 = node1->next;
            }else{
                p->next = node2;
                node2 = node2->next;
            }

            p = p->next;
        }

        // 连接剩余节点
        if (node1 != nullptr) {
            p->next = node1;
        } else {
            p->next = node2;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }

    ListNode* midPre(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};
#endif

// 做题目的宗旨为：能过就行，哈哈哈🤣
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        std::vector<int> nums{};

        while(head != nullptr){
            nums.push_back(head->val);
            head = head->next;
        }

        sort(nums.begin(),nums.end());

        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        for (int num : nums){
            ListNode* tmp = new ListNode(num);
            p->next = tmp;
            p = p->next;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }

};