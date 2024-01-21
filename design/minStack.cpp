// 155. Min Stack
// https://leetcode.com/problems/min-stack

class MinStack {
public:
    stack <int> st1, miniStack;

    MinStack() {

    }
    
    void push(int val) {
        st1.push(val);

        if(miniStack.size() == 0 || val <=miniStack.top()) {
            miniStack.push(val);
        }
    }
    
    void pop() {
        if(miniStack.top() == st1.top()) {
            miniStack.pop();
        }
        st1.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return miniStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */