#include "../core.hpp"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        std::vector<std::pair<int,int>> dp(nums.size());

        dp[0] = {nums[0], nums[0]};
        int ans = dp[0].second;

        for (int i = 1; i < nums.size() ;i++){
            dp[i].first = std::min(std::min(dp[i-1].first * nums[i] , dp[i-1].second * nums[i]),nums[i]);
            dp[i].second = std::max(std::max(dp[i-1].first * nums[i] , dp[i-1].second * nums[i]),nums[i]);
            if (dp[i].second > ans){
                ans = dp[i].second;
            }
        }

        return ans;
    }
};