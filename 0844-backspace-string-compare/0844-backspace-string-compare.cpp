class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int si = s.length() - 1;
        int ti = t.length() - 1;
        
        int sn = 0;
        int tn = 0;
        while (si >= 0 || ti >= 0)
        {
            if (si >= 0 && s[si] == '#')
            {
                ++sn;
                --si;
                continue;
            }
            if (ti >= 0 && t[ti] == '#')
            {
                ++tn;
                --ti;
                continue;
            }
            if (sn > 0)
            {
                --sn;
                --si;
                continue;
            }
            if (tn > 0)
            {
                --tn;
                --ti;
                continue;
            }
            if (si < 0 || ti < 0 || s[si] != t[ti])
                return false;
            
            --si;
            --ti;
        }
        
        return true;
    }
};