class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (target == "0000") return 0;

        int answer = 0;
        unordered_set<string> visited;
        queue<string> q;
        q.push("0000"s);
        for (auto& s : deadends)
        {
            if (s == "0000") return -1;
            visited.insert(s);
        }
        
        while (!q.empty())
        {
            int sz = q.size();
            for (int i=0;i<sz;++i)
            {
                auto cur = q.front();
                q.pop();
                if (cur == target)
                    return answer;
                for (int ci=0;ci<cur.length();++ci)
                {
                    auto s = cur;
                    auto c = s[ci];
                    s[ci] = c == '9' ? '0' : c + 1;
                    if (visited.find(s) == visited.end())
                    {
                        q.push(s);
                        visited.insert(s);                        
                    }
                    
                    s[ci] = c == '0' ? '9' : c - 1;
                    if (visited.find(s) == visited.end())
                    {
                        q.push(s);
                        visited.insert(s);                        
                    }
                }
            }
            ++answer;
        }
        
        return -1;
    }
};