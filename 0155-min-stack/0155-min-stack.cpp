struct ms {
    int val, mnm;
};

class MinStack {
public:
    stack<ms> s;
    MinStack() {}
    
    void push(int val) {
        int mnm = min(val, s.size() > 0 ? getMin() : INT_MAX);
        ms t = {val, mnm};
        s.push(t);
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().val;
    }
    
    int getMin() {
        return s.top().mnm;
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