class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCnt = nums[0] == 0 ? 1 : 0;
        int zeroIdx = nums[0] == 0 ? 0 : -1;
        int n = 1;
        for (int i=1;i<nums.size();++i)
        {
            if (nums[i] == 0)
            {
                zeroIdx = i;
                ++zeroCnt;
                if (zeroCnt > 1)
                    return vector<int>(nums.size(), 0);
            }
            else
                n *= nums[i];
        }

        vector<int> product(nums.size(), 0);
        if (zeroIdx >= 0)
        {
            product[zeroIdx] = n * (zeroIdx != 0 ? nums[0] : 1);
            return product;
        }
            
        product[0] = n;
        for (int i=1;i<nums.size();++i)
        {
            n /= nums[i];
            n *= nums[i-1];
            product[i] = n;
        }
        return product;
    }
};