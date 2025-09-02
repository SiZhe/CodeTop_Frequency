#include "../core.hpp"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<std::vector<int>> ans{};
        std::vector<int> tmp{};
        BT(ans,nums,tmp,0);
        return ans;
    }

    void BT(std::vector<std::vector<int>>& ans ,std::vector<int>& nums,std::vector<int>& tmp,int i){
        if (i == nums.size()){
            ans.push_back(tmp);
            return;
        }else{
            tmp.push_back(nums[i]);
            BT(ans,nums,tmp,i+1);
            tmp.pop_back();

            BT(ans,nums,tmp,i+1);
        }
    }
};