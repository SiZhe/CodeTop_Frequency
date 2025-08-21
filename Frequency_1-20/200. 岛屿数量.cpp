#include "../core.hpp"

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0 ; i < m ; i++){
            for (int j = 0 ; j < n ; j++){
                if (grid[i][j] == '1'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(std::vector<std::vector<char>>& grid,int i ,int j){
        if (!isValid(grid,i,j)){
            return;
        }
        if (grid[i][j] == '0'){
            return;
        }

        grid[i][j] = '0';

        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }

    bool isValid(std::vector<std::vector<char>>& grid, int c, int r){
        return (c >= 0 && c < grid.size()) && (r >= 0 && r < grid[0].size());
    }
};