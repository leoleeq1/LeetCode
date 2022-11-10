class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> cs;
        for (int i=s.length()-1;i>=0;--i)
        {
            char c = s[i];
            if (!cs.empty() && c == cs.top())
            {
                cs.pop();
            }
            else
                cs.push(c);
        }
        s = "";
        
        while (!cs.empty())
        {
            s += cs.top();
            cs.pop();
        }
        return s;
    }
};