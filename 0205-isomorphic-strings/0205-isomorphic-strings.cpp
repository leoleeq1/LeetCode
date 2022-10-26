class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unsigned char map[512];
        
        memset(map, 0x80, sizeof(map));
        
        for (int i=0;i<s.length();++i)
        {
            if (map[0 + s[i]] == 0x80 && map[256 + t[i]] == 0x80)
            {
                map[0 + s[i]] = t[i];
                map[256 + t[i]] = s[i];
            }
            else if (!(map[0 + s[i]] == t[i] && map[256 + t[i]] == s[i]))
            {
                return false;
            }
        }
        return true;
    }
};