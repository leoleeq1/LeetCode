class Solution {
public:
    bool findEntries(queue<int>& q, vector<int>& v)
    {
        bool result = false;
        for (int i=0;i<v.size();++i)
        {
            if (v[i] == 0)
            {
                q.push(i);
                result = true;
            }
        }
        return result;
    }
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        unordered_map<int, set<int>> m;
        vector<int> v(num);
        for (int i=0;i<pre.size();++i)
        {
            m[pre[i][1]].insert(pre[i][0]);
            ++v[pre[i][0]];
        }

        vector<int> result;
        queue<int> q;
        if (!findEntries(q, v))
        {
            return vector<int>();
        }
            
        while (!q.empty())
        {
            int c = q.front();
            q.pop();
            result.push_back(c);
            for (auto p : m[c])
            {
                if (--v[p] == 0)
                {
                    q.push(p);
                }
            }
        }
        return result.size() == num ? result : vector<int>();
    }
};