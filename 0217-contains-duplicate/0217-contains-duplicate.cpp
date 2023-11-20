class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int prev = 1000000001;
        for (auto n : nums)
        {
            if (prev == n)
                return true;
            prev = n;
        }
        return false;
    }
};