class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> v;
        sort(nums.begin(), nums.end());
        
        auto cnt = nums.size();
        auto i = 0;
        while (i < cnt && nums[i] <= 0)
        {
            auto t = nums[i];
            auto l = i + 1;
            auto r = nums.size() - 1;
            while (l < r)
            {
                auto ln = nums[l];
                auto rn = nums[r];
                auto sum = ln + rn + t;
                if (sum == 0)
                {
                    v.push_back({t, ln, rn});
                }
                
                if (sum > 0)
                {
                    while (r > l && nums[r] == rn)
                        --r;
                }
                else
                {
                    while (l < r && nums[l] == ln)
                        ++l;
                }
            }
            
            while (i < cnt && nums[i] == t)
            {
                ++i;
            }
        }
        return v;
    }
};