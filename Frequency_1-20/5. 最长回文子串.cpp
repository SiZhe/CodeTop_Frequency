#include "../core.hpp"

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        std::vector<std::vector<bool>> dp(n,std::vector<bool>(n,false));

        for (int i = 0 ; i < n ; i++){
            dp[i][i] = true;
        }

        int maxLen = 1;
        int start = 0;

        for (int len = 2 ; len <= n ; len++){
            for (int i = 0 ; i < n ;i++ ){
                int j = i + len - 1;
                if (j > n-1){
                    break;
                }
                if(len == 2 && s[i] == s[j]){
                    dp[i][j] = true;
                }else if (len != 2){
                    if(s[i] == s[j]){
                        dp[i][j] = dp[i+1][j-1];
                    }else{
                        dp[i][j] = false;
                    }
                }

                if (dp[i][j] == true){
                    if (len > maxLen){
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start,maxLen);
    }
};