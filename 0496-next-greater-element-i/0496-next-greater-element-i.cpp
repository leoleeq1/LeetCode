class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> memo(10001, -1);
        stack<int> s;
        
        auto n = nums2.size();
        for (int i=n-1;i>=0;--i)
        {
            while (!s.empty() && s.top() <= nums2[i])
                s.pop();
            auto nge = s.empty() ? -1 : s.top();
            memo[nums2[i]] = nge;
            s.push(nums2[i]);
        }
        
        for (int i=0;i<nums1.size();++i)
        {
            nums1[i] = memo[nums1[i]];
        }
        return nums1;
    }
};