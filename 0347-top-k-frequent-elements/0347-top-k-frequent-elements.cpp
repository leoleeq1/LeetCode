class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto i : nums)
        {
            ++m[i];
        }
        vector<int> v(m.size());
        int i=0;
        for (auto& p : m)
        {
            v[i++] = p.first;
        }
        sort(v.begin(), v.end(), [&](int l, int r) -> bool {return m[l] > m[r];});
        v.erase(v.begin() + k, v.end());
        return v;
    }
};