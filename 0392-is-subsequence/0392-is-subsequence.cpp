class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (t.length() == 0)
        {
            if (s.length() == 0)
                return true;
            return false;
        }
        else if (s.length() == 0)
        {
            return true;
        }
        
        int len = 0;
        for (int i=0;i<t.length();++i)
        {
            if (t[i] == s[len])
            {
                ++len;
                if (len == s.length())
                    return true;
            }
        }
        
        return false;
    }
};