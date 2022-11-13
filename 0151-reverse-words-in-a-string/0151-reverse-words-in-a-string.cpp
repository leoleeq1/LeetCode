class Solution {
public:
    string reverseWords(string s) {
        string t;
        string result;
        for (int i=0;i<s.length();)
        {
            i = s.find_first_not_of(' ', i);
            int j = s.find_first_of(" \0", i);
            if (i == -1)
                break;
            result = s.substr(i, j - i) + " " + result;
            i = j;
        }
        result.erase(result.find_last_not_of(' ') + 1);
        return result;
    }
};