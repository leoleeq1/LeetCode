class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> m;
        for (auto& word : words)
        {
            m[word] += 1;
        }
        vector<pair<string,int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), [](auto& l, auto& r) {return l.second == r.second ? l.first < r.first : l.second > r.second;});
        vector<string> result(k);
        for (int i=0;i<k;++i)
            result[i] = v[i].first;
        return result;
    }
};