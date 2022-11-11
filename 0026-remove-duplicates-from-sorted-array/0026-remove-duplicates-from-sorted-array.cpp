class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int n = 1000;
        for (int i=0;i<nums.size();++i)
        {
            if (nums[i] == n)
                continue;
            
            nums[k++] = n = nums[i];
        }
        return k;
    }
};