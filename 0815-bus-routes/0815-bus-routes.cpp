class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        
        unordered_map<int, vector<int>> buses;//that can take at i'th bus stop
        for (int i=0;i<routes.size();++i)
        {
            for (int j=0;j<routes[i].size();++j)
            {
                buses[routes[i][j]].push_back(i);
            }
        }
        
        queue<int> q[2];
        unordered_set<int> visited;
        int nb = 1;
        for (int i=0;i<buses[source].size();++i)
        {
            q[0].push(buses[source][i]);
        }
        
        int i=0,j=1;
        while (!q[i].empty())
        {
            while (!q[i].empty())
            {
                auto bus = q[i].front();
                q[i].pop();
                
                if (visited.count(bus) > 0)
                    continue;
                visited.insert(bus);
                
                auto& route = routes[bus];
                for (int k=0;k<route.size();++k)
                {
                    if (route[k] == target)
                        return nb;
                    
                    auto& nbuses = buses[route[k]];
                    for (int l=0;l<nbuses.size();++l)
                    {
                        if (visited.count(nbuses[l]) > 0)
                            continue;
                        
                        q[j].push(nbuses[l]);
                    }
                }                
            }
            ++nb;
            swap(i,j);
        }
        return -1;
    }
};