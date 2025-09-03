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
// 效率很低
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        tool(root,ans);
        return ans;
    }

    void tool(TreeNode* root,int& t){
        if (root == nullptr){
            return;
        }
        int h = level(root->left) + level(root->right);
        t = std::max(t,h);
        tool(root->left,t);
        tool(root->right,t);
    }

    int level(TreeNode* node){
        if (node == nullptr){
            return 0;
        }

        int l = level(node->left);
        int r = level(node->right);
        return l > r ? l+1 : r+1;
    }
};