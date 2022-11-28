class Solution {
public:
    vector<vector<int>> result;
    unordered_set<int> set;
    vector<int> v;
    int used = 0;
    void f(vector<int>& nums)
    {
        for (int i=0;i<nums.size();++i)
        {
            if (set.count(i)) continue;
            v.push_back(nums[i]);
            set.insert(i);
            used += 1;
            if (used == nums.size())
                result.push_back(v);
            else
                f(nums);
            used -= 1;
            set.erase(i);
            v.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        f(nums);
        return result;
    }
};