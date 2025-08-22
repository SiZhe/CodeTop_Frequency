#include "../core.hpp"

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        std::vector<int> nums{};
        for (int i = 1 ; i < s.size(); i++){
            nums.push_back(i);
        }

        std::vector<std::vector<int>> ans;
        std::vector<int> tmp{};
        BT(tmp,nums,ans,0);

        std::vector<std::string> ansss{};
        for (auto a : ans){
            string a1 = s.substr(0,a[0]);
            string a2 = s.substr(a[0],a[1]-a[0]);
            string a3 = s.substr(a[1],a[2]-a[1]);
            string a4 = s.substr(a[2]);
            if (Judge(a1) && Judge(a2) &&Judge(a3) &&Judge(a4)){
                std::string anss = a1 + '.' + a2 + '.' + a3 + '.' + a4;
                ansss.push_back(anss);
            }
        }
        return ansss;
    }

    void BT(std::vector<int>& tmp ,std::vector<int> nums,std::vector<std::vector<int>>& ans ,int i ){
        if(i == nums.size()){
            if (tmp.size() == 3){
                ans.push_back(tmp);
                return;
            }
        }else{
            if (tmp.size() < 3){
                tmp.push_back(nums[i]);
                BT(tmp,nums,ans,i+1);
                tmp.pop_back();
            }
            BT(tmp,nums,ans,i+1);
        }
    }

    bool Judge(std::string a){
        if (a.size() > 3 || a.size() < 1){
            return false;
        }else if (a.size() == 2){
            if (a[0] == '0'){
                return false;
            }
        }else if (a.size() == 3){
            if (stoi(a) > 255 || a[0] == '0'){
                return false;
            }
        }
        return true;
    }



};