#include "../core.hpp"

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> dp(n,nums[0]);
        int max = nums[0];
        for (int i = 1 ; i < n ; i++){
            dp[i] = std::max(nums[i],dp[i-1]+nums[i]);
            if (dp[i] > max){
                max = dp[i];
            }
        }
        return max;
    }
};