class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sz = nums.size();
        vector<int> answer(sz, 1);
        for (int i=1;i<sz;++i)
        {
            answer[i] = answer[i-1] * nums[i-1];
        }
        int right = 1;
        for (int i=sz-1;i>=0;--i)
        {
            answer[i] *= right;
            right *= nums[i];
        }
        
        return answer;
    }
};