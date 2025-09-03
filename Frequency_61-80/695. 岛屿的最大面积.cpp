#include "../core.hpp"

// 深度遍历
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxarea = 0;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if (grid[i][j] == 1){
                    int area = 0;
                    dfs(grid,i,j,area);
                    if (area > maxarea){
                        maxarea = area;
                    }
                }
            }
        }

        return maxarea;
    }

    void dfs(std::vector<std::vector<int>>& grid,int i ,int j,int& area){
        if(!judge(grid,i,j) || grid[i][j] == 0){
            return;
        }

        if(grid[i][j] == 1){
            grid[i][j] = 0;
            area++;
            dfs(grid,i+1,j,area);
            dfs(grid,i-1,j,area);
            dfs(grid,i,j+1,area);
            dfs(grid,i,j-1,area);
        }
    }

    bool judge(std::vector<std::vector<int>>& grid,int i ,int j){
        return ((i >= 0)&&(i < grid.size()))&&((j >= 0)&&(j < grid[0].size()));
    }
};