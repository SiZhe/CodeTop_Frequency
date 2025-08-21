#include "../core.hpp"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int max = 1;
        std::vector<int> dp(nums.size(),1);
        for (int i = 0 ; i < nums.size() ; i++){
            for (int j = 0 ; j < i ;j++){
                if (nums[j] < nums[i]){
                    dp[i] = std::max(1 + dp[j],dp[i]);
                }
            }
            max = std::max(max,dp[i]);
        }
        return max;
    }
};