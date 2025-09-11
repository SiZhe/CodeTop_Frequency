#include "../core.hpp"

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> dp(temperatures.size(),0);
        for (int i = temperatures.size()-2 ; i >= 0 ; i--){
            int t = i+1;
            int next = 1;
            while (t < temperatures.size()){
                if (temperatures[t] > temperatures[i]){
                    dp[i] = next;
                    break;
                }else{
                    if (dp[t] != 0){
                        next += dp[t];
                        t += dp[t];
                    }else{
                        break;
                    }
                }
            }
        }
        return dp;
    }
};