class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int s = 0;
        int e = n - 1;
        while (s <= e)
        {
            int m = (s + e) / 2;
            if (target == nums[m])
                return m;
            
            if (nums[m] < nums[e])
            {
                if (target > nums[m] && target <= nums[e])
                    s = m + 1;
                else
                    e = m - 1;
            }
            else
            {
                if (target > nums[m] || target < nums[0])
                    s = m + 1;
                else
                    e = m - 1;
            }
        }
        return -1;
    }
};