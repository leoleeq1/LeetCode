class Solution {
public:
    string longestPalindrome(string s) {
        string longest = "";
        
        for (int i=0;i<s.length();++i)
        {
            for (int j=0;j<s.length()-i;++j)
            {
                auto l = i;
                auto r = s.length() - j - 1;
                auto len = r - l + 1;
                if (len < longest.length()) break;
                if (isPalindrome(s, l, r))
                {
                    if (len > longest.length())
                        longest = s.substr(l, len);
                }
            }
        }
        
        return longest;
    }
    
    bool isPalindrome(const string& s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] != s[r])
                return false;
            ++l;
            --r;
        }
        return true;
    }
};