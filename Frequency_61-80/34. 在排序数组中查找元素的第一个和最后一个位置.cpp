#include "../core.hpp"

// 先找一个，然后两边搜索得了
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;

        int t = -1;

        while (l <= r){
            int mid = l + (r-l)/2;
            if ( nums[mid] < target){
                l = mid + 1;
            }else if (nums[mid] > target){
                r = mid - 1;
            }else{
                t = mid;
                break;
            }
        }

        if (t == -1){
            return {-1,-1};
        }else{
            int m = t;
            int n = t;

            while (m>=0 && nums[m] == target){
                m--;
            }

            while (n < nums.size() && nums[n] == target){
                n++;
            }

            return {m+1,n-1};
        }
    }
};