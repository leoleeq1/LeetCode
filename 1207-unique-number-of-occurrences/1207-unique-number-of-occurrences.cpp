class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occ;
        unordered_set<int> unique;
        
        for (auto i : arr)
            ++occ[i];
        
        for (auto o : occ)
            if (unique.count(o.second))
                return false;
            else
                unique.insert(o.second);
        
        return true;
    }
};