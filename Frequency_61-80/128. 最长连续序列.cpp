#include "../core.hpp"

// 能跑就行哈哈哈哈
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        sort(nums.begin(),nums.end());
        int maxlength = 1;
        for (int i = 0; i < nums.size()-1; i++){
            int length = 1;
            while (i < nums.size()-1 && (nums[i] + 1 == nums[i+1] || nums[i] == nums[i+1])){
                if (nums[i] == nums[i+1]){
                    i++;
                }else{
                    i++;
                    length++;
                }
            }
            if (length > maxlength){
                maxlength = length;
            }
        }
        return maxlength;
    }
};