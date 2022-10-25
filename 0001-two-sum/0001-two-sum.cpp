class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result(2);
        int sum;
        
        for (int i=0;i<nums.size();++i)
        {
            for (int j=i+1;j<nums.size();++j)
            {
                sum = nums[i] + nums[j];
                if (sum == target)
                {
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
            }
        }
        return result;
    }
};