class Solution {
public:
    char vowels[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    bool halvesAreAlike(string s) {
        unordered_map<char, int> map[2];
        int m = s.length() / 2;
        for (int i=0;i<m;++i)
        {
            ++map[0][s[i]];
        }
        for (int i=m;i<s.length();++i)
        {
            ++map[1][s[i]];
        }
        
        int l=0, r=0;
        for (int i=0;i<10;++i)
        {
            l += map[0][vowels[i]];
            r += map[1][vowels[i]];
        }
        return l == r;
    }
};