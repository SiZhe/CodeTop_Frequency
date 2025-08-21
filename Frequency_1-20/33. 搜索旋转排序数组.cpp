#include "../core.hpp"

// 注意等号
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(l <= r){
            int mid = (l + r)/2;
            if (nums[mid] == target){
                return mid;
            }else if (nums[l] <= nums[mid]){
                // 左边是有序的
                if(nums[l] <= target && target < nums[mid]){
                    // 在有序的这边
                    r = mid - 1;
                }else{
                    // 在乱序的一边
                    l = mid + 1;
                }
            }else{
                //右边是有序的
                if(nums[mid] < target && target <= nums[r]){
                    // 在有序的这边
                    l = mid + 1;
                }else{
                    // 在乱序的一边
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};
