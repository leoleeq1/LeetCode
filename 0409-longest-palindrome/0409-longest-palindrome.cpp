class Solution {
public:
    int longestPalindrome(string s) {
        short letters[256];
        memset(letters, 0, sizeof(letters));
        int len = s.length();
        for (int i=0;i<len;++i)
            ++letters[s[i]];
        
        bool usedSingleLetter = false;
        int pal = 0;
        for (int i=65;i<123;++i)
        {
            if ((letters[i] & 1) == 1 && !usedSingleLetter)
            {
                ++pal;
                usedSingleLetter = true;
            }
            pal += letters[i] / 2 * 2;
        }
        return pal;
        
    }
};