#include "../core.hpp"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::map<int,int> map{};
        for (int num : nums){
            map[num]++;
        }

        int size = nums.size();
        for (int num:nums){
            if (map[num] > size/2){
                return num;
            }
        }

        return -1;
    }
};