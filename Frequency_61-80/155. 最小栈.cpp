#include "../core.hpp"

// 在pop()的时候要更新min
class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        st.push(val);

        if (val < min){
            minst.push(val);
            min = val;
        }else{
            minst.push(min);
        }
    }

    void pop() {
        st.pop();
        minst.pop();

        if(st.empty()){
            min = INT_MAX;
        }else{
            min = minst.top();
        }
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minst.top();
    }

    std::stack<int> st;
    std::stack<int> minst;
    int min = INT_MAX;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */