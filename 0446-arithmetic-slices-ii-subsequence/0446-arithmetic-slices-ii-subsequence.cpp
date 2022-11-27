typedef long long LL;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ret = 0;
        vector<unordered_map<LL, LL>> cnt(n);
        for (int i=1;i<n;++i)
        {
            for (int j=0;j<i;++j)
            {
                LL d = (LL)nums[i] - (LL)nums[j];
                cnt[i][d] += cnt[j][d] + 1;
                ret += cnt[j][d];
            }
        }
        return ret;
    }
};