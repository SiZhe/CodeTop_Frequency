#include "../core.hpp"

// 低效的回溯法
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> ans{};
        std::vector<int> tmp{};
        BT(ans,tmp,target,0,candidates);
        std::set<std::vector<int>> tmp1{};
        for (auto an : ans){
            sort(an.begin(),an.end());
            tmp1.insert(an);
        }
        std::vector<std::vector<int>> ans1{};
        for (auto t : tmp1){
            ans1.push_back(t);
        }
        return ans1;
    }

    void BT(std::vector<std::vector<int>>& ans, std::vector<int>& tmp,int target,int sum,std::vector<int>& candidates){
        if (sum == target){
            ans.push_back(tmp);
        }else{
            for(int i = 0; i < candidates.size(); i++){
                if (sum+candidates[i] <= target){
                    tmp.push_back(candidates[i]);
                    BT(ans,tmp,target,sum+candidates[i],candidates);
                    tmp.pop_back();
                }
            }
        }
    }
};