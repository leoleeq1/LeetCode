class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a=nums[0],mnm=nums[0],mxm=nums[0];
        
        for (int i=1;i<nums.size();++i)
        {
            if (nums[i] < 0)
                swap(mnm, mxm);
            
            mnm = min(mnm * nums[i], nums[i]);
            mxm = max(mxm * nums[i], nums[i]);
            
            a = mxm > a ? mxm : a;
        }
        return a;
    }
};