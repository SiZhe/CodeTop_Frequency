#include "../core.hpp"

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stk;
        for (int i = 0 ; i < s.size() ;i++){
            if(s[i] == '('||s[i] == '{'||s[i] == '['){
                stk.push(s[i]);
            }else{
                if(stk.empty()){
                    return false;
                }

                char a = s[i];
                char b = stk.top();

                if (b == '(' && a == ')'){
                    stk.pop();
                }else if (b == '{' && a == '}'){
                    stk.pop();
                }else if (b == '[' && a == ']'){
                    stk.pop();
                }else{
                    return false;
                }
            }
        }

        if (stk.empty()){
            return true;
        }else{
            return false;
        }
    }
};