class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int half = nums.size() / 2;
        unordered_map<int, int> map;
        for (auto n : nums)
            ++map[n];
        for (auto [n, cnt] : map)
        {
            if (cnt > half) return n;
        }
        return -1;
    }
};