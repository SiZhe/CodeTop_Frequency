#include "../core.hpp"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int u = 0;
        int d = matrix.size()-1;
        int l = 0;
        int r = matrix[0].size()-1;

        std::vector<int> ans{};

        while(true){
            for (int i = l ; i <= r ; i++){
                ans.push_back(matrix[u][i]);
            }
            u++;
            if (u > d) break;

            for (int i = u ; i <= d ; i++){
                ans.push_back(matrix[i][r]);
            }
            r--;
            if (l > r) break;

            for (int i = r ; i >= l ; i--){
                ans.push_back(matrix[d][i]);
            }
            d--;
            if (u > d) break;

            for (int i = d ; i >= u ; i--){
                ans.push_back(matrix[i][l]);
            }
            l++;
            if (l > r) break;
        }

        return ans;
    }
};