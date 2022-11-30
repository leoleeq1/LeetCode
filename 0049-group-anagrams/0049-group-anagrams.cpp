class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mm;
        for (auto& str : strs)
        {
            auto sorted = str;
            sort(sorted.begin(), sorted.end());
            mm[sorted].push_back(str);
        }
        
        vector<vector<string>> ret;
        for (auto& p : mm)
            ret.push_back(p.second);
        return ret;
    }
};