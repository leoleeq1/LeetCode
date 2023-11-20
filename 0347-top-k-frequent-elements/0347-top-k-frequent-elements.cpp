class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() == k)
            return nums;

        unordered_map<int, int> freq;
        for (auto n : nums)
        {
            ++freq[n];
        }

        vector<int> top(freq.size());
        transform(freq.begin(), freq.end(), top.begin(), [](auto p) { return p.first; });
        sort(top.begin(), top.end(), [&](int l, int r) { return freq[l] > freq[r]; });
        top.erase(top.begin() + k, top.end());
        return top;
    }
};