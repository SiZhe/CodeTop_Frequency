#include "../core.hpp"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int max = 0;
        for (int i = 1 ; i < prices.size() ;i++){
            min = std::min(min,prices[i]);
            max = std::max(max,prices[i]-min);
        }
        return max;
    }
};