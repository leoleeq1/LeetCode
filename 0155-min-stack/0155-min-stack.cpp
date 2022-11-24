struct ms {
    int val, mnm;
};

class MinStack {
public:
    ms *s;
    int capacity = 4;
    int size = 0;
    int mnm = INT_MAX;
    MinStack() {s = (ms*)malloc(sizeof(ms) * capacity);}
    
    void push(int val) {
        mnm = min(val, mnm);
        ms t = {val, mnm};
        if (size >= capacity)
        {
            capacity *= 2;
            s = (ms*)realloc(s, sizeof(ms) * capacity);
        }
        s[size++] = t;
    }
    
    void pop() {
        --size;
        if (size > 0)
            mnm = s[size - 1].mnm;
        else
            mnm = INT_MAX;
    }
    
    int top() {
        return s[size-1].val;
    }
    
    int getMin() {
        return s[size-1].mnm;
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