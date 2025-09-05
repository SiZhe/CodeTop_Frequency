#include "../core.hpp"

class Solution {
public:
#if 0
    // 冒泡法
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0 ; i < n-1; i++){
            bool flag = false;
            for (int j = 0 ; j < n-1-i ;j++){
                if (nums[j] == 0){
                    std::swap(nums[j],nums[j+1]);
                    flag = true;
                }
            }
            if (flag == false){
                return;
            }
        }
    }
#endif
    void moveZeroes(vector<int>& nums) {
        int j = 0;

        for (int i = 0 ; i < nums.size(); i++){
            if (nums[i] != 0){
                nums[j++] = nums[i];
            }
        }

        for (;j < nums.size(); j++){
            nums[j] = 0;
        }
    }

};