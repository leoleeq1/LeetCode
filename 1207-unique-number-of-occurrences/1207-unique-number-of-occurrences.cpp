class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occ;
        unordered_set<int> unique;
        
        for (auto i : arr)
            ++occ[i];
        
        for (auto o : occ)
            unique.insert(o.second);
        
        return occ.size() == unique.size();
    }
};