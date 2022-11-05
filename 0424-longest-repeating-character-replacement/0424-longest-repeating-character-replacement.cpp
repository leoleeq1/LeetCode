class Solution {
public:
    int getLength(unordered_map<char, int>& m, bool withLongestChar = true)
    {
        int result = 0;
        int longest = 0;
        for (auto& pair : m)
        {
            longest = max(pair.second, longest);
            result += pair.second;
        }
        if (!withLongestChar)
            result -= longest;
        return result;
    }
    char getLongest(unordered_map<char, int>& m)
    {
        int longest = 0;
        char c = 0;
        for (auto& pair : m)
        {
            if (longest < pair.second)
            {
                longest = pair.second;
                c = pair.first;
            }
        }
        return c;
    }
    int characterReplacement(string s, int k) {
        int longest = 0;
        int changed = 0;
        
        unordered_map<char, int> m;
        char lc = 0;
        
        int p1 = 0;
        int p2 = 0;
        bool grow = true;
        while (p2 < s.length())
        {
            if (grow)
            {
                m[s[p2]] += 1;

                if (lc == 0 || m[lc] < m[s[p2]])
                    lc = s[p2];
            }

            changed = getLength(m, false);            
            if ((k - changed) >= 0)
            {
                longest = max(p2 - p1 + 1, longest);
                ++p2;
                grow = true;
            }
            else
            {
                m[s[p1]] = max(m[s[p1]] - 1, 0);
                if (lc == s[p1])
                    lc = getLongest(m);
                ++p1;
                grow = false;
            }
        }
        
        return longest;
    }
};