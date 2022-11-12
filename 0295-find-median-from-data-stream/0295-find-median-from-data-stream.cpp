class MedianFinder {
public:
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<>> minh;
    bool odd = false;
    MedianFinder() {}
    
    void addNum(int num) {
        odd = !odd;
        if (maxh.size() == 0 || maxh.top() > num)
        {
            maxh.push(num);
            if (maxh.size() > (minh.size() + 1))
            {
                minh.push(maxh.top());
                maxh.pop();
            }
        }
        else
        {
            minh.push(num);
            if (minh.size() > (maxh.size() + 1))
            {
                maxh.push(minh.top());
                minh.pop();
            }
        }
    }
    
    double findMedian() {
        return odd 
            ? (maxh.size() > minh.size() ? maxh.top() : minh.top())
            : (maxh.top() + minh.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */