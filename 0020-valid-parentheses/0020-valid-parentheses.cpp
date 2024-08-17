class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> map;
        map[')'] = '(';
        map['}'] = '{';
        map[']'] = '[';
        for (auto c : s)
        {
            if (map.find(c) != map.end())
            {
                if (stk.empty() || stk.top() != map[c])
                    return false;
                stk.pop();
                continue;
            }
            
            stk.push(c);
        }
        
        return stk.empty();
    }
};