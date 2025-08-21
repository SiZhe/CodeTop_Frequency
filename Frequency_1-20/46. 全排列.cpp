#include "../core.hpp"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::vector<std::vector<int>> ans{};
        BT(ans,nums,0);
        return ans;
    }

    void BT(std::vector<std::vector<int>>& ans,std::vector<int>& nums,int i){
        if (i == nums.size()){
            ans.push_back(nums);
            return;
        }else{
            for(int k = i ; k < nums.size() ; k++){
                std::swap(nums[i],nums[k]);
                BT(ans,nums,i+1);
                std::swap(nums[i],nums[k]);
            }
        }
    }
};