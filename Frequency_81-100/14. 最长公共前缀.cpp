#include "../core.hpp"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string ans{};
        for (int i = 0 ; i < strs[0].size(); i++){
            char c = strs[0][i];
            bool flag = true;
            for (auto str : strs){
                if (str.size() > i && str[i] == c){
                    flag = true;
                }else{
                    flag = false;
                    break;
                }
            }
            if (flag == true){
                ans += c;
            }else{
                return ans;
            }
        }
        return ans;
    }
};