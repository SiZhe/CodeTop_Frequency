#include "core.hpp"


void BT(std::vector<std::vector<int>>& ans,std::vector<int>& nums,int k){
    if (k == nums.size()){
        ans.push_back(nums);
        return;
    }else{
        for (int i = k ; i < nums.size(); i++){
            std::swap(nums[i],nums[k]);
            BT(ans,nums,k+1);
            std::swap(nums[i],nums[k]);
        }
    }
}

int main() {
    std::vector<int> nums{1,2,3};
    std::vector<std::vector<int>> ans{};
    BT(ans,nums,0);
    for (auto an : ans) {
        std::cout << "[ " ;
        for (int a: an) {
            std::cout << a  << " ";
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}