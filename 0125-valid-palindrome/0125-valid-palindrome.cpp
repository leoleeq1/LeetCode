class Solution {
public:
    bool isPalindrome(string s) {
        auto l = 0;
        auto r = s.length() - 1;
        
        while (l < r)
        {
            if (!isAlphanumeric(s[l]))
            {
                ++l;
                continue;
            }
            if (!isAlphanumeric(s[r]))
            {
                --r;
                continue;
            }
            
            if (tolower(s[l]) != tolower(s[r]))
                return false;
            ++l;
            --r;
        }
        return true;
    }
    
    bool isAlphanumeric(char c)
    {
        if (c >= '0' && c <= '9'
           || c >= 'a' && c <= 'z'
           || c >= 'A' && c <= 'Z')
            return true;
        return false;
    }
};