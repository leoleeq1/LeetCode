class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int lsum = 0;
        int rsum = 0;
        int pi = 0;
        
        for (int i=1;i<nums.size();++i)
        {
            rsum += nums[i];
        }
        
        while (lsum != rsum)
        {   
            lsum += nums[pi++];
            
            if (pi >= nums.size())
                return -1;
            
            rsum -= nums[pi];
        }
        return pi;
    }
};