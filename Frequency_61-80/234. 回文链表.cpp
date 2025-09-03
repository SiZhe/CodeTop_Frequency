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

// 用快慢指针 可以用 fast是否为空 判断 link的node是偶数个还是奇数个
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head->next == nullptr){
            return true;
        }

        std::stack<int> st{};
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            st.push(slow->val);
            slow = slow->next;
        }

        // 奇数个
        if (fast != nullptr){
            slow = slow->next;
        }

        while (slow != nullptr){
            if (slow->val == st.top()){
                st.pop();
                slow = slow->next;
            }else{
                return false;
            }
        }

        return true;
    }
};