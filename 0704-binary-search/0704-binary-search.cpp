class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int start = 0;
        int end = len;
        int mid;
        int val;
        while (start < end)
        {
            mid = (start + end) / 2;
            val = nums[mid];
            if (val < target)
            {
                start = mid + 1;
            }
            else if (val > target)
            {
                end = mid;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }
};