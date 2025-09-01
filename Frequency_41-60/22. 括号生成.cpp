#include "../core.hpp"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::vector<int>> ans{};
        std::vector<int> tmp{};

        BT(ans,tmp,n,1);
        std::vector<string> ans1{};
        for (auto an :ans){
            std::string g(2*n,')');
            g[0] = '(';
            for (auto a :an){
                g[a] = '(';
            }
            ans1.push_back(g);
        }
        std::vector<string> ans2{};
        for (auto an1 : ans1){
            if (judge(an1)){
                ans2.push_back(an1);
            }
        }
        return ans2;
    }

    void BT(std::vector<std::vector<int>>& ans,std::vector<int>& tmp,int n,int i){
        if (i == 2*n - 1){
            ans.push_back(tmp);
            return;
        }

        if (tmp.size() == n-1){
            ans.push_back(tmp);
            return;
        }else{
            tmp.push_back(i);
            BT(ans,tmp,n,i+1);
            tmp.pop_back();

            BT(ans,tmp,n,i+1);
        }
    }

    bool judge(std::string tmp){
        std::stack<char> st{};
        for (char t : tmp){
            if (t == ')'){
                if (st.empty()){
                    return false;
                }else{
                    st.pop();
                }
            }else{
                st.push(t);
            }
        }

        if (st.empty()){
            return true;
        }else{
            return false;
        }
    }
};