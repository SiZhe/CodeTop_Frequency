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

// 需要再次复习
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return butTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }

    TreeNode* butTree(std::vector<int>& preorder,int i ,int j ,std::vector<int>& inorder,int m,int n){
        if (i > j || m > n){
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[i]);

        for (int k = m ; k <= n ;k++){
            if (preorder[i] == inorder[k]){
                node->left =  butTree(preorder,i+1,i+k-m,inorder,m,k-1);
                node->right =  butTree(preorder,i+1+k-m,j,inorder,k+1,n);
            }
        }
        return node;
    }
};