#include "../core.hpp"

// long long mm = (long long) mid*mid; 这里需要强制转换
// int mid = d + (u - d)/2; 这样取中点更加的安全
class Solution {
public:
    int mySqrt(int x) {
        int d = 0;
        int u = x;
        int ans{};
        while (d <= u){
            int mid = d + (u - d)/2;
            long long mm = static_cast<long long>(mid)*mid;
            // long long mm = (long long)mid*mid;
            if (mm <= x){
                ans = mid;
                d = mid + 1;
            }else{
                u = mid - 1;
            }
        }
        return ans;
    }
};