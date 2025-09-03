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
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> ans{};
        preOrd(root,ans);
        return ans;
    }

    void preOrd(TreeNode* node,std::vector<int>& ans){
        if (node == nullptr){
            return;
        }
        ans.push_back(node->val);
        preOrd(node->left,ans);
        preOrd(node->right,ans);
    }
};