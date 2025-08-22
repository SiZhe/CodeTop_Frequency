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

// 两两合并
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = nullptr;
        for (int i = 0 ; i < lists.size(); i++){
            ans = merge(ans,lists[i]);
        }
        return ans;
    }

    ListNode* merge(ListNode* list1 , ListNode* list2){
        ListNode* dummy = new ListNode();
        ListNode* p = dummy;
        while(list1 != nullptr && list2 != nullptr){
            if (list1->val < list2->val){
                p->next = list1;
                list1 = list1->next;
            }else{
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }

        if (list1 != nullptr){
            p->next = list1;
        }else{
            p->next = list2;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};

//优先队列，然后重构
class SolutionOther {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::priority_queue<int,std::vector<int>,std::greater<int>> pq{};
        for(int i = 0 ; i < lists.size(); i++) {
            while (lists[i] != nullptr){
                pq.push(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }

        ListNode* dummy = new ListNode();
        ListNode* p = dummy;
        while (!pq.empty()){
            ListNode* q = new ListNode(pq.top());
            pq.pop();
            p->next = q;
            p = p->next;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};