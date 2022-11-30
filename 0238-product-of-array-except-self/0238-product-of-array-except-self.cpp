class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix=1, postfix=1;
        vector<int> ret(n, 1);
        for (int i=0;i<n;++i)
        {
            ret[i] *= prefix;
            ret[n-i-1] *= postfix;
            prefix = prefix * nums[i];
            postfix = postfix * nums[n-i-1];
        }
        return ret;
    }
};