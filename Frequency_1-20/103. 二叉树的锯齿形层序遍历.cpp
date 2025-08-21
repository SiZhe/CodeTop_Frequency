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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::vector<std::vector<int>> ans{};
        int level = Level(root);

        for (int i = 0 ; i < level ; i++){
            std::vector<int> tmp{};
            if (i & 1 == 1){
                // 奇数
                levelOrd2(root,tmp,i);
            }else{
                // 偶数
                levelOrd1(root,tmp,i);
            }
            ans.push_back(tmp);
        }

        return ans;
    }

    void levelOrd1(TreeNode* node,std::vector<int>& tmp,int i){
        if (node == nullptr){
            return;
        }

        if (i == 0){
            tmp.push_back(node->val);
        }

        levelOrd1(node->left,tmp,i-1);
        levelOrd1(node->right,tmp,i-1);
    }

    void levelOrd2(TreeNode* node,std::vector<int>& tmp,int i){
        if (node == nullptr){
            return;
        }

        if (i == 0){
            tmp.push_back(node->val);
        }

        levelOrd2(node->right,tmp,i-1);
        levelOrd2(node->left,tmp,i-1);
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