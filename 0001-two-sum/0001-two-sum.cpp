class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        auto idx = vector<int>(nums.size());
        std::iota(idx.begin(), idx.end(), 0);
        std::sort(idx.begin(), idx.end(), [&nums](int l, int r) { return nums[l] < nums[r]; });
        int s = 0;
        int e = nums.size() - 1;
        
        while (s < e)
        {
            auto sum = nums[idx[s]] + nums[idx[e]];
            if (sum == target)
                break;
            if (sum > target)
                --e;
            else if (sum < target)
                ++s;
        }
        return vector<int>{idx[s], idx[e]};
    }
};