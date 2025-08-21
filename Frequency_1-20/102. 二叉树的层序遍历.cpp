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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ans{};
        int level = Level(root);
        for (int i = 0 ; i < level ; i++){
            std::vector<int> tmp{};
            levelOrd(root,tmp,i);
            ans.push_back(tmp);
        }
        return ans;
    }

    void levelOrd(TreeNode* node,std::vector<int>& tmp, int level){
        if (node == nullptr){
            return;
        }

        if (level == 0){
            tmp.push_back(node->val);
        }
        levelOrd(node->left,tmp,level-1);
        levelOrd(node->right,tmp,level-1);
    }

    int Level(TreeNode* node){
        if(node == nullptr){
            return 0;
        }

        int left = Level(node->left);
        int right = Level(node->right);

        return left > right ? left + 1 : right + 1;
    }
};