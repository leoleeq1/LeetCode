class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        if (bank.size() == 0)
            return -1;
        
        unordered_map<string, int> m;
        m[start] = 0;
        for (int i=0;i<bank.size();++i)
            m[bank[i]] = 0;
        
        if (m.find(end) == m.end())
            return -1;
        
        queue<string> q;
        q.push(start);
        
        char genes[] = {'A', 'C', 'G', 'T'};
        
        while (!q.empty())
        {
            string s = q.front();
            q.pop();
            
            if (s == end)
                return m[s];
            
            for (int i=0;i<8;++i)
            {
                string str = s;
                for (int g=0;g<4;++g)
                {
                    str[i] = genes[g];
                    if (str != s && m.find(str) != m.end() && m[str] == 0)
                    {
                        m[str] = m[s] + 1;
                        q.push(str);
                    }
                }                
            }
        }
        
        return -1;
    }
};