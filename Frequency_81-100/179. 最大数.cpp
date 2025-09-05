#include "../core.hpp"

// int 转 string: std::to_string();
// 背: sort(tmp.begin(),tmp.end(),[](const auto& a, const auto& b){return a+b > b+a;};

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        std::vector<std::string> tmp{};
        for (auto num : nums){
            tmp.push_back(std::to_string(num));
        }
        sort(tmp.begin(),tmp.end(),[](const auto& a, const auto& b){
            return a+b > b+a;
        });
        std::string ans{};
        for (auto t : tmp){
            ans += t;
        }
        if (ans[0] == '0'){
            return "0";
        }else{
            return ans;
        }
    }
};