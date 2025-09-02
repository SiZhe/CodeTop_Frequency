#include "../core.hpp"

// 没什么好说的，背诵题
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i+1]){
            i--;
        }
        if (i >= 0){
            int j = nums.size() - 1;
            while ( j>= 0 && nums[i] >= nums[j]){
                j--;
            }
            std::swap(nums[i],nums[j]);
        }

        sort(nums.begin() + i + 1,nums.end());
    }
};