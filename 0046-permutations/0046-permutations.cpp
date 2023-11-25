class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> visit;
        backtrack(nums, visit);
        return result;
    }
    
    void backtrack(vector<int>& nums, vector<int>& visit)
    {
        if (visit.size() == nums.size())
        {
            result.push_back(visit);
            return;
        }
        
        for (auto n : nums)
        {
            if (find(visit.begin(), visit.end(), n) != visit.end()) continue;
            visit.push_back(n);
            backtrack(nums, visit);
            visit.pop_back();
        }
    }
private:
    vector<vector<int>> result;
};