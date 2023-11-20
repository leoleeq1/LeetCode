class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        vector<vector<char>> pairs{{'(', ')'}, {'{', '}'}, {'[', ']'}};
        for (auto c : s)
        {
            for (auto& p : pairs)
            {
                if (c == p[0])
                {
                    stk.push(c);
                    break;
                }
                else if (c == p[1])
                {
                    if (stk.size() == 0 || stk.top() != p[0])
                        return false;
                    stk.pop();
                }
            }
        }
        return stk.size() == 0;
    }
};