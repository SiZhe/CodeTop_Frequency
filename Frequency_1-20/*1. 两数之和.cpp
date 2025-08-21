#include "../core.hpp"

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> hashmap{};

        for(int i = 0 ; i < nums.size() ; i++){
            int t = target - nums[i];

            auto it = hashmap.find(t);

            if (it != hashmap.end()){
                return {i,it->second};
            }

            hashmap[nums[i]] = i;
        }

        return {};
    }
};