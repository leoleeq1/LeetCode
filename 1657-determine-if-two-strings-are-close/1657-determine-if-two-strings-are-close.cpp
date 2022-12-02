class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> occ[2] = {vector<int>(26), vector<int>(26)};
        
        for (auto c : word1)
            ++occ[0][c-'a'];
        for (auto c : word2)
            ++occ[1][c-'a'];
        
        vector<int> v[2];
        for (int i=0;i<26;++i)
        {
            if (occ[0][i] == 0 && occ[1][i] != 0 || occ[0][i] != 0 && occ[1][i] == 0)
                return false;
            v[0].push_back(occ[0][i]);
            v[1].push_back(occ[1][i]);
        }
        
        for (int i=0;i<2;++i)
            sort(v[i].begin(), v[i].end());
        for (int i=0;i<v[0].size();++i)
            if (v[0][i] != v[1][i])
                return false;
        return true;
    }
};