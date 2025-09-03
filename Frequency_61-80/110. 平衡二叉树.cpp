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
    bool isBalanced(TreeNode* root) {
        if (root == nullptr){
            return true;
        }
        int n1 = level(root->left);
        int n2 = level(root->right);

        if (std::abs(n1-n2) > 1){
            return false;
        }else{
            return isBalanced(root->left) && isBalanced(root->right);
        }
    }

    int level(TreeNode* node){
        if (node == nullptr){
            return 0;
        }

        int left = level(node->left);
        int right = level(node->right);

        return left > right ? left+1 : right+1;
    }
};