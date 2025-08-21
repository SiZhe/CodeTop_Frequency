#include "../core.hpp"

// 时间复杂度 O(n log n)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 默认大根堆
        std::priority_queue<int> pq{};

        for (auto num : nums){
            pq.push(num);
        }

        for (int i = 0 ; i < k-1 ; i++){
            pq.pop();
        }

        return pq.top();
    }
};