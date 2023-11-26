struct pair_hash
{
    template <class T1, class T2>
        size_t operator() (const std::pair<T1, T2> &pair) const
    {
        return hash<T1>{}(pair.first) & hash<T2>{}(pair.second);
    }
};

class State
{
public:
    int id;
    int distFromStart;
    
    State(int id, int dist)
    {
        this->id = id;
        this->distFromStart = dist;
    }
};

class Solution {
public:
    unordered_map<pair<int, int>, int, pair_hash> weights;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> distTo(n+1, INT_MAX);
        queue<State> q;
        distTo[k] = 0;
        q.push({k, 0});
        for (auto& t : times)
        {
            weights[{t[0], t[1]}] = t[2];
        }
        
        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            
            if (cur.distFromStart > distTo[cur.id]) continue;
            
            for (int to=1;to<=n;++to)
            {
                auto w = weight(cur.id, to);
                if (w < 0) continue;
                auto nextDist = w + cur.distFromStart;
                if (nextDist >= distTo[to]) continue;
                distTo[to] = nextDist;
                q.push({to, nextDist});
            }
        }
        
        auto ans = *max_element(distTo.begin()+1, distTo.end());
        return ans == INT_MAX ? -1 : ans;
    }
    
    int weight(int from, int to)
    {
        return weights.find({from, to}) != weights.end() ? weights[{from, to}] : -1;
    }
};