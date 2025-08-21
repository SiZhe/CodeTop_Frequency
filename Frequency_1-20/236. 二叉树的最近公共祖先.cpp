#include "../core.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> st;

        std::vector<TreeNode*> path1;
        Path(st,p,root,path1);
        st.clear();
        std::vector<TreeNode*> path2;
        Path(st,q,root,path2);

        for (int i = std::min(path1.size(),path2.size()) -1 ; i >= 0 ; i--){
            if (path1[i] == path2[i]){
                return path1[i];
            }
        }

        return nullptr;
    }

    void Path(std::vector<TreeNode*>& st, TreeNode* target,TreeNode* node,std::vector<TreeNode*>& path){
        if (node == nullptr){
            return;
        }
        st.push_back(node);

        if (node == target){
            path = st;
            return;
        }

        Path(st,target,node->left,path);
        Path(st,target,node->right,path);
        st.pop_back();
    }
};
