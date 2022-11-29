class RandomizedSet {
public:
    unordered_set<int> set;
    
    RandomizedSet() {}
    bool insert(int val) {
        if (set.count(val))
            return false;
        set.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if (set.count(val))
        {
            set.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        auto it = set.begin();
        advance(it, rand() % set.size());
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */