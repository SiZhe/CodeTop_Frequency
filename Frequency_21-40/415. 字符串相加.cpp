#include "../core.hpp"

class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size()-1;
        int n2 = num2.size()-1;

        int carry = 0;
        std::string ans{};

        while (n1 >= 0 || n2 >= 0 || carry == 1){
            int sum = carry;
            int i = 0;
            int j = 0;
            if (n1 >= 0){
                i = num1[n1] - '0';
                n1--;
            }

            if (n2 >= 0){
                j = num2[n2] - '0';
                n2--;
            }
            sum += (i+j);
            if (sum >= 10){
                carry = 1;
                sum %= 10;
            }else{
                carry = 0;
            }

            ans.push_back(sum + '0');
        }

        std::reverse(ans.begin(),ans.end());
        return ans;
    }
};