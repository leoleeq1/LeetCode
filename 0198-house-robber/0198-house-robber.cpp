class Solution {
public:
    int res[100];
    int rob(vector<int>& nums, int i)
    {
        if (i >= nums.size())
            return 0;
        if (res[i] != -1)
            return res[i];
        if (i >= (nums.size()-2))
            return res[i] = nums[i];
        if (i == (nums.size()-3))
            return res[i] = nums[i] + nums[i+2];
        return res[i] = nums[i] + max(rob(nums, i+2), rob(nums,i+3));
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        memset(res, -1, sizeof(res));
        return max(rob(nums, 0), rob(nums, 1));
    }
};