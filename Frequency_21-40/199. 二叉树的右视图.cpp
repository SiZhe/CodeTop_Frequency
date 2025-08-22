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
    vector<int> rightSideView(TreeNode* root) {
        int level = Level(root);

        std::vector<int> ans{};
        for (int i = 0 ; i < level ; i++){
            int tmp{};
            levelOrd(root,tmp,i);
            ans.push_back(tmp);
        }
        return ans;
    }

    void levelOrd(TreeNode* node,int& ans, int i){
        if (node == nullptr){
            return;
        }

        if (i == 0){
            ans = node->val;
            return;
        }

        levelOrd(node->left,ans,i-1);
        levelOrd(node->right,ans,i-1);
    }

    int Level(TreeNode* node){
        if (node == nullptr){
            return 0;
        }

        int left = Level(node->left);
        int right = Level(node->right);

        return left > right ? left+1 : right+1;
    }
};