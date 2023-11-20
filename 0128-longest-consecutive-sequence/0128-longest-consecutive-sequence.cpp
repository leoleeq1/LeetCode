class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        unordered_map<int, pair<int, int>> seq;
        int longest = 1;
        for (auto n : nums)
        {
            if (seq.find(n) != seq.end())
                continue;
            
            auto& cur = seq[n];
            cur.first = n;
            cur.second = n;

            if (seq.find(n-1) != seq.end())
            {
                cur.first = seq[n-1].first;
            }
            
            if (seq.find(n+1) != seq.end())
            {
                cur.second = seq[n+1].second;
            }
            
            if (seq.find(cur.first) != seq.end())
            {
                seq[cur.first].second = cur.second;
            }
            
            if (seq.find(cur.second) != seq.end())
            {
                seq[cur.second].first = cur.first;
            }
            
            longest = max(longest, cur.second - cur.first + 1);
        }
        return longest;
    }
};