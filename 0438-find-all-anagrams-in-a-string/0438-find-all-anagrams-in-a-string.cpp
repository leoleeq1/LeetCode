class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size())
            return result;
        
        unordered_map<char, int> sm, pm;
        int p1 = 0;
        int p2 = p.size() - 1;
        bool found = false;
        int len = s.size() - 1;
        
        for (int i=0;i<p.size();++i)
        {
            if (pm.find(p[i]) == pm.end())
                pm[p[i]] = 0;
            pm[p[i]] += 1;
        }
        
        for (int i=0;i<p.size();++i)
        {
            if (sm.find(s[i]) == sm.end())
                sm[s[i]] = 0;
            sm[s[i]] += 1;
        }
        
        while (p2 <= len)
        {
            for (const auto& pair : pm)
            {
                if (sm.find(pair.first) == sm.end() || sm[pair.first] != pair.second)
                    goto CONTINUE;
            }
            result.push_back(p1);
            
            CONTINUE:
            sm[s[p1]] = max(sm[s[p1]] - 1, 0);
            ++p1;
            ++p2;
            if (p2 >= s.size())
                continue;

            if (sm.find(s[p2]) == sm.end())
                sm[s[p2]] = 0;
            sm[s[p2]] += 1;
        }
        
        return result;
    }
};