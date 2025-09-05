#include "../core.hpp"

// o(log n) 想二分搜索
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0 ;
        int r = nums.size()-1;

        return bsearch(nums,l,r);
    }

    int bsearch(vector<int>& nums,int l ,int r){
        if (l > r){
            return -1;
        }

        int mid = l + (r - l)/2;
        bool lflag = left(nums,mid);
        bool rflag = right(nums,mid);

        if (rflag && lflag){
            return mid;
        }

        int leftpos = bsearch(nums,l,mid-1);
        if (leftpos == -1){
            int rightpos = bsearch(nums,mid+1 ,r);
            return rightpos;
        }else{
            return leftpos;
        }
    }



    bool left(vector<int>& nums,int pos){
        if (pos == 0){
            return true;
        }else{
            if (nums[pos] > nums[pos-1]){
                return true;
            }else{
                return false;
            }
        }
    }

    bool right(vector<int>& nums,int pos){
        if (pos == nums.size()-1){
            return true;
        }else{
            if (nums[pos] > nums[pos+1]){
                return true;
            }else{
                return false;
            }
        }
    }
};