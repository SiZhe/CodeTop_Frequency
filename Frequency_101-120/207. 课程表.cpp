#include "../core.hpp"

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::vector<int> inner(numCourses,0);
        std::vector<std::vector<int>> graph(numCourses,std::vector<int>{});
        for (auto& edge : prerequisites){
            inner[edge[0]]++;
            graph[edge[1]].push_back(edge[0]);
        }

        std::stack<int> st{};

        for (int i = 0 ; i <numCourses ; i++){
            if(inner[i] == 0){
                st.push(i);
            }
        }

        int lesson = 0;
        while(!st.empty()){
            int lesson1 = st.top();
            st.pop();
            lesson++;
            for (auto c : graph[lesson1]){
                inner[c]--;
                if(inner[c] == 0){
                    st.push(c);
                }
            }
        }

        return lesson == numCourses;
    }
};