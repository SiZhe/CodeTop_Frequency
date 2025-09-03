#include "../core.hpp"


// 记住这个动态规划方程吧 dp[i][j] = 1 + std::min(dp[i-1][j-1],std::min(dp[i-1][j],dp[i][j-1]));
// 最小值(上,下,左上)+1
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;

        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<std::vector<int>> dp(m,std::vector<int>(n,0));

        for (int i = 0 ; i < m ; i++){
            if (matrix[i][0] == '1'){
                dp[i][0] = 1;
                if (dp[i][0] > ans){
                    ans = dp[i][0];
                }
            }else{
                dp[i][0] = 0;
            }
        }

        for (int j = 0 ; j < n ; j++){
            if (matrix[0][j] == '1'){
                dp[0][j] = 1;
                if (dp[0][j] > ans){
                    ans = dp[0][j];
                }
            }else{
                dp[0][j] = 0;
            }
        }

        for (int i = 1 ; i < m ; i++){
            for (int j = 1 ; j < n ; j++){
                if (matrix[i][j] == '1'){
                    dp[i][j] = 1 + std::min(dp[i-1][j-1],std::min(dp[i-1][j],dp[i][j-1]));
                    if (dp[i][j] > ans){
                        ans = dp[i][j];
                    }
                }
            }
        }

        return ans * ans;
    }
};