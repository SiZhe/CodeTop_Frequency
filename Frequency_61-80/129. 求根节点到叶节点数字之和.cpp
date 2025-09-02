#include "../core.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 注意pop_back()的位置
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        std::vector<int> tmp{};
        std::vector<int> ans{};
        dfs(root,tmp,ans);
        int result = 0;
        for (int an : ans){
            result += an;
        }
        return result;
    }

    void dfs(TreeNode* node, std::vector<int>& tmp,std::vector<int>& ans){
        if (node == nullptr){
            return;
        }

        tmp.push_back(node->val);

        if (node->left == nullptr && node->right == nullptr){
            int t = tool(tmp);
            ans.push_back(t);
            //tmp.pop_back();
            //return;
        }
        dfs(node->left,tmp,ans);
        dfs(node->right,tmp,ans);
        tmp.pop_back();
    }

    int tool(const std::vector<int>& tmp) {
        int num = 0;
        for (int t : tmp){
            num = num * 10 + t;
        }
        return num;
    }

};