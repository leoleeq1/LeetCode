class Solution {
public:
    unordered_map<int, int> map;
    int getRoot(int n)
    {
        int prev = n;
        while (n != -1 && map.find(n) != map.end() && map[n] != prev)
        {
            prev = n;
            n = map[n];
        }
        return prev;
    }
    void setParent(int n, int parent)
    {
        if (map.find(n) == map.end())
            map[n] = parent;
        else
        {
            while (n != -1 && map.find(n) != map.end() && map[n] != parent)
            {
                int t = map[n];
                map[n] = parent;
                n = t;
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int m = isConnected.size();
        int n = isConnected[0].size();
        
        for (int y=0;y<m;++y)
        {
            bool any = false;
            for (int x=n-1;x>=0;--x)
            {
                if (isConnected[y][x] && x != y)
                {
                    int root = min(getRoot(x), getRoot(y));
                    setParent(x, root);
                    setParent(y, root);
                    any = true;
                }
            }
            if (!any)
                map[y] = -1;
        }
        
        unordered_set<int> set;
        int ret = 0;
        for (auto pair : map)
        {
            if (pair.second == -1)
                ++ret;
            else
                set.insert(getRoot(pair.first));
        }
        return ret + set.size();
    }
};