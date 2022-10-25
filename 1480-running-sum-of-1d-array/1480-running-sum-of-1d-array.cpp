class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size);
        
        int sum = 0;
        for (int i=0;i<size;++i)
            result[i] = sum += nums[i];
        
        return result;
    }
};