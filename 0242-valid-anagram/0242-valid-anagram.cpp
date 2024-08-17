class Solution {
public:
    bool isAnagram(string s, string t) {
        int slen = s.length();
        int tlen = t.length();
        if (slen != tlen) return false;
        
        int cnt[26] = {0,};
        
        for (int i=0;i<slen;++i)
        {
            ++cnt[s[i] - 'a'];
        }
        
        for (int i=0;i<slen;++i)
        {
            if (--cnt[t[i] - 'a'] < 0)
                return false;
        }
        
        return true;
    }
};