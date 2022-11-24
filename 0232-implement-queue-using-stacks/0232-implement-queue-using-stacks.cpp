class MyQueue {
public:
    stack<int> q;
    MyQueue() {}
    void push(int x) {
        stack<int> s;
        while (!q.empty())
        {
            s.push(q.top());
            q.pop();
        }
        q.push(x);
        while (!s.empty())
        {
            q.push(s.top());
            s.pop();
        }
    }
    
    int pop() {
        int val = q.top();
        q.pop();
        return val;
    }
    
    int peek() {
        return q.top();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */