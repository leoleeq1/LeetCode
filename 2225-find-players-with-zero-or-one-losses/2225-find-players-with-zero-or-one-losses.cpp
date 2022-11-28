class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> winners;
        unordered_map<int, int> losers;
        
        for (int i=0;i<matches.size();++i)
        {
            ++winners[matches[i][0]];
            ++losers[matches[i][1]];
        }
        
        vector<vector<int>> ret(2);
        for (auto pair : winners)
        {
            if (losers.find(pair.first) == losers.end())
                ret[0].push_back(pair.first);
        }
        for (auto pair : losers)
        {
            if (pair.second == 1)
                ret[1].push_back(pair.first);
        }
        
        sort(ret[0].begin(), ret[0].end());
        sort(ret[1].begin(), ret[1].end());
        
        return ret;
    }
};