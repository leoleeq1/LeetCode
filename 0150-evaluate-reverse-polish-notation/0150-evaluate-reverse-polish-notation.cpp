class Solution {
public:
    using fptr = int (*)(int, int);
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, fptr> map;
        map["*"] = [](int l, int r) { return l * r; };
        map["/"] = [](int l, int r) { return l / r; };
        map["+"] = [](int l, int r) { return l + r; };
        map["-"] = [](int l, int r) { return l - r; };
        
        stack<int> s;
        for (auto& token : tokens)
        {
            if (map.find(token) != map.end())
            {
                int r = s.top(); s.pop();
                int l = s.top(); s.pop();
                int res = map[token](l, r);
                s.push(res);
            }
            else
                s.push(stoi(token));
        }
        return s.top();
    }
};