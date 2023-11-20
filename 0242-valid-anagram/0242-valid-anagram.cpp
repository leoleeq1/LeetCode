class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        for (int i=0;i<s.length();++i)
        {
            if (s[i] != t[i])
                return false;
        }
        return true;
    }
};