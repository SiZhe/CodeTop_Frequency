#include "../core.hpp"

// 类似二叉树的搜索 以右上角为根节点
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0;
        int j = n-1;

        while (i < m && j >= 0){
            if (target == matrix[i][j]){
                return true;
            }else if (target < matrix[i][j]){
                j--;
            }else if (target > matrix[i][j]){
                i++;
            }
        }

        return false;
    }
};
