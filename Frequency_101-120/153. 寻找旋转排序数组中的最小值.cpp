#include "../core.hpp"

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int min = nums[l];

        while (l <= r){
            int mid = l + (r-l)/2;

            if (nums[mid] >= nums[l]){
                // 左侧是有序的
                if (min > nums[l]){
                    min = nums[l];
                }
                l = mid + 1;
            }else{
                //右侧是有序的
                if (min > nums[mid]){
                    min = nums[mid];
                }
                r = mid - 1;
            }
        }
        return min;
    }
};