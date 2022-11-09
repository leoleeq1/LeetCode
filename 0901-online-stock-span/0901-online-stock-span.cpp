class Price {
public:
    int price = 0;
    Price* front = nullptr;
    Price(int price) : price(price), front(nullptr) {}
    Price(int price, Price* front) : price(price), front(front) {}
};

class StockSpanner {
public:
    Price* tail;
    StockSpanner() : tail(nullptr) {}
    
    int next(int price) {
        Price* p = new Price(price, tail);
        tail = p;
        int i = 1;
        p = p->front;
        while (p != nullptr && p->price <= price)
        {
            ++i;
            p = p->front;
        }
        return i;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */