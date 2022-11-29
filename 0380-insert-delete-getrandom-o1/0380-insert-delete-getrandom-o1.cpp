class RandomizedSet {
public:
    unordered_map<int, int> set;
    vector<int> v;
    
    RandomizedSet() {}
    bool insert(int val) {
        if (set.find(val) != set.end())
            return false;
        v.push_back(val);
        set[val] = v.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (set.find(val) == set.end())
            return false;
        int i = set[val];
        v[i] = v[v.size()-1];
        set[v[i]] = i;
        v.pop_back();
        set.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand() % set.size()];;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */