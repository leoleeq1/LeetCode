class Solution {
public:
    int sqr(int n, int exp)
    {
        if (exp == 0)
            return 1;
        for (int i=1;i<exp;++i)
            n *= n;
        return n;
    }
    int atoi(string s)
    {
        int num = 0;
        for (int i=0;i<s.length();++i)
        {
            int si = s.length() - 1 - i;
            num += (s[si] - '0') * sqr(10, i);
        }
        return num;
    }
    int matchedIndex(const string& s, int opened)
    {
        int i=opened+1;
        int cnt = 1;
        while (i < s.length())
        {
            if (s[i] == '[')
                ++cnt;
            else if (s[i] == ']')
            {
                --cnt;
                if (cnt == 0)
                    return i;
            }
            ++i;
        }
        return s.length() - 1;
    }
    bool isNumber(char c)
    {
        return c >= '0' && c <= '9';
    }
    string decodeString(string s) {
        string str;
        for (int i=0;i<s.length();++i)
        {
            if (isNumber(s[i]))
            {
                int opened = i + 1;
                for (;s[opened]!='[';++opened);
                int closed = matchedIndex(s, opened);
                string sub = decodeString(s.substr(opened + 1, closed - opened - 1));
                int cnt = atoi(s.substr(i, opened - i));
                for (int j=0;j<cnt;++j)
                {
                    str += sub;
                }
                i = closed;
            }
            else
            {
                str += s[i];
            }
        }
        return str;
    }
};