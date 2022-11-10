class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        for (int i=0;i<s.length();++i)
        {
            char c = s[i];
            if (result.length() != 0 && result[result.length()-1] == c)
            {
                result.pop_back();
            }
            else
            {
                result += c;
            }
        }
        return result;
    }
};