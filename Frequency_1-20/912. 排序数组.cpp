#include "../core.hpp"

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        QuickSort(nums,0,nums.size()-1);
        return nums;
    }

    void QuickSort(std::vector<int>& nums, int l ,int r){
        if (l >= r){
            return;
        }

        int pos = Partition(nums,l,r);
        QuickSort(nums,l,pos-1);
        QuickSort(nums,pos+1,r);
    }

    int Partition(std::vector<int>& nums, int l ,int r){
        int num = nums[l];

        while(l < r){
            while(l < r && nums[r] > num){
                r--;
            }
            if (l < r){
                nums[l] = nums[r];
                l++;
            }

            while(l < r && nums[l] < num){
                l++;
            }
            if (l < r){
                nums[r] = nums[l];
                r--;
            }
        }

        nums[l] = num;
        return l;
    }
};