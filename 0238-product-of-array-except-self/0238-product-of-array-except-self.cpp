class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n), postfix(n);
        for (int i=0;i<n;++i)
        {
            prefix[i] = (i > 0 ? prefix[i-1] : 1) * nums[i];
            postfix[n-i-1] = (i > 0 ? postfix[n-i] : 1) * nums[n-i-1];
        }
        
        vector<int> ret(n);
        for (int i=0;i<n;++i)
        {
            ret[i] = (i > 0 ? prefix[i-1] : 1) * (i < n-1 ? postfix[i+1] : 1);
        }
        return ret;
    }
};