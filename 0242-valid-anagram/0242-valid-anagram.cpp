class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, int> m[2];
        for (int i=0;i<s.length();++i)
        {
            ++m[0][s[i]];
            ++m[1][t[i]];
        }
        
        for (auto& p : m[0])
        {
            if (m[1].find(p.first) == m[1].end() || m[1][p.first] != p.second)
                return false;
        }
        return true;
    }
};