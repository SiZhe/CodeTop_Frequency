#include "../core.hpp"

#if 0
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const auto& a, const auto& b){
            return a[0] < b[0];
        });

        std::vector<std::vector<int>> ans{};
        ans.push_back({intervals[0][0],intervals[0][1]});

        for (int i = 0 ; i < intervals.size() ; i++){
            int p = ans.back()[0];
            int q = ans.back()[1];
            int m = intervals[i][0];
            int n = intervals[i][1];

            if ( p <= m && n <= q){
                continue;
            }else if (p <= m && m <= q && n > q){
                ans.back()[1] = n;
            }else if ( p > m && p <= n && n <= q){
                ans.back()[0] = m;
            }else if( m <= p && q <= n){
                ans.back()[0] = m;
                ans.back()[1] = n;
            } else {
                ans.push_back({m,n});
            }
        }

        return ans;
    }
};
#endif

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const auto& a, const auto& b){
            return a[0] < b[0];
        });

        std::vector<std::vector<int>> ans{};
        ans.push_back({intervals[0][0],intervals[0][1]});

        for (int i = 0 ; i < intervals.size() ; i++){
            int l = intervals[i][0];
            int r = intervals[i][1];

            if (ans.back()[1] < l){
                ans.push_back({l,r});
            }else{
                ans.back()[1] = std::max(r,ans.back()[1]);
            }
        }

        return ans;
    }
};