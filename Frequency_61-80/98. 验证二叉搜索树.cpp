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
// 用中序遍历来判断：二叉搜索树的中序遍历为升序
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        std::vector<int> ans{};
        ord(root,ans);
        if(ans.empty()){
            return true;
        }
        for (int i = 1; i < ans.size() ;i++){
            if (ans[i] <= ans[i-1]){
                return false;
            }
        }
        return true;
    }

    void ord(TreeNode* node, std::vector<int>& ans){
        if (node == nullptr){
            return;
        }

        ord(node->left,ans);
        ans.push_back(node->val);
        ord(node->right,ans);
    }
};