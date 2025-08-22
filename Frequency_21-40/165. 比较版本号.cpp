#include "../core.hpp"

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int j = 0 ;
        std::vector<std::string> v1{""};
        for (int i = 0 ; i < version1.size() ; i++){
            if(version1[i] != '.'){
                v1[j].push_back(version1[i]);
            }else{
                v1.push_back("");
                j++;
            }
        }
        std::vector<int> v1nums{};
        for(int i = 0 ; i < v1.size() ;i++){
            int num = stoi(v1[i]);
            v1nums.push_back(num);
        }

        j = 0 ;
        std::vector<std::string> v2{""};
        for (int i = 0 ; i < version2.size() ; i++){
            if(version2[i] != '.'){
                v2[j].push_back(version2[i]);
            }else{
                v2.push_back("");
                j++;
            }
        }
        std::vector<int> v2nums{};
        for(int i = 0 ; i < v2.size() ;i++){
            int num = stoi(v2[i]);
            v2nums.push_back(num);
        }


        if (v1nums.size() > v2nums.size()){
            int k = (v1nums.size() - v2nums.size());
            for (int i = 0 ; i < k;i++){
                v2nums.push_back(0);
            }
        }else if (v1nums.size() < v2nums.size()){
            int k = (v2nums.size() - v1nums.size());
            for (int i = 0 ; i < k;i++){
                v1nums.push_back(0);
            }
        }

        for (int i = 0 ; i < v1nums.size();i++){
            if (v1nums[i] < v2nums[i]){
                return -1;
            }else if (v1nums[i] > v2nums[i]){
                return 1;
            }
        }

        return 0;
    }
};