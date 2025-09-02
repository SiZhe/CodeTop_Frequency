#include "../core.hpp"

// std::string 的 push_back() 只能push char类型
// += 可以 + std::string
class Solution {
public:
    string reverseWords(string s) {
        std::vector<std::string> tmp1{};
        for (int i = 0 ; i < s.size() ; i++){
            std::string tmp2{};
            while(s[i] != ' ' && i < s.size()){
                tmp2.push_back(s[i]);
                i++;
            }
            if(!tmp2.empty()){
                tmp1.push_back(tmp2);
            }
        }

        reverse(tmp1.begin(),tmp1.end());

        std::string ans{};
        for (int i = 0 ; i < tmp1.size()-1 ; i++){
            ans += (tmp1[i] + " ");
        }
        ans += tmp1.back();
        //ans.push_back(tmp1.back());
        return ans;
    }
};