#include "../core.hpp"

// dfs + 标记(记得回溯uesd)
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0 ; i < board.size() ; i++){
            for (int j = 0 ; j < board[0].size() ; j++){
                if (board[i][j] == word[0]){
                    bool flag = false;
                    vector<vector<bool>> used(board.size(),std::vector<bool>(board[0].size(),false));
                    search(board,used,i,j,word,0,flag);
                    if(flag){
                        return flag;
                    }
                }
            }
        }
        return false;
    }

    void search(vector<vector<char>>& board,vector<vector<bool>>& used, int i ,int j,string word,int k,bool& flag){
        if (k == word.size()){
            flag = true;
            return;
        }

        if (!tool(board,i,j)){
            return;
        }else if (used[i][j]){
            return;
        }else if (board[i][j] != word[k]){
            return;
        }else if (board[i][j] == word[k]){
            used[i][j] = true;
            search(board,used,i+1,j,word,k+1,flag);
            search(board,used,i-1,j,word,k+1,flag);
            search(board,used,i,j+1,word,k+1,flag);
            search(board,used,i,j-1,word,k+1,flag);
            used[i][j] = false;
        }
    }

    bool tool(vector<vector<char>>& board,int i ,int j){
        return (i >= 0 && i < board.size())&&( j>=0 && j < board[0].size());
    }
};