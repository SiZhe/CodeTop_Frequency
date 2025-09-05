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
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flag = false;
        bt(flag,root,targetSum,0);
        return flag;
    }

    void bt(bool& flag,TreeNode* node,int targetSum,int sum){
        if (node == nullptr || flag == true){
            return;
        }

        sum += node->val;

        if (node->left == nullptr && node->right ==  nullptr){
            if (sum == targetSum){
                flag = true;
            }
        }

        bt(flag,node->left,targetSum,sum);
        bt(flag,node->right,targetSum,sum);
    }
};