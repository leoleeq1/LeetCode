class Solution {
public:
    string makeGood(string s) {
        if (s.length() <= 1)
            return s;

        string result;
        bool removed = false;
        for (int i=0;i<s.length();)
        {
            if (abs(s[i] - s[i+1]) == 32)
            {
                i += 2;
                removed = true;
            }
            else
            {
                result += s[i++];
            }
        }
        
        if (removed)
            return makeGood(result);
        return result;
    }
};