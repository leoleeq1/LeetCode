class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        int m = val;
        if (!s.empty())
            m = min(m, get<1>(s.top()));
        s.push({val, m});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return get<0>(s.top());
    }
    
    int getMin() {
        return get<1>(s.top());
    }
private:
    stack<pair<int, int>> s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */