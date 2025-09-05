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

// 和 112 一样
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        std::vector<int> tmp{};
        std::vector<std::vector<int>> ans{};
        dfs(root,0,targetSum,tmp,ans);
        return ans;
    }

    void dfs(TreeNode* node ,int sum, int targetSum,std::vector<int>& tmp,std::vector<std::vector<int>>& ans){
        if (node == nullptr){
            return;
        }
        tmp.push_back(node->val);
        sum += node->val;

        if (node->left == nullptr && node->right == nullptr){
            if (sum == targetSum){
                ans.push_back(tmp);
            }
        }

        dfs(node->left,sum,targetSum,tmp,ans);
        dfs(node->right,sum,targetSum,tmp,ans);
        //sum -= node->val;
        tmp.pop_back();
    }
};