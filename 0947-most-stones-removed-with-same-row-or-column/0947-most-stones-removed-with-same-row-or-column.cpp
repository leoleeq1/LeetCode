class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int, vector<int>> row, col;
        
        for (int i=0;i<stones.size();++i)
        {
            col[stones[i][0]].push_back(i);
            row[stones[i][1]].push_back(i);
        }
        
        unordered_set<int> s;
        function<int(int)> bfs = [&](int stone) -> int
        {
            if (s.count(stone))
                return 0;
            s.insert(stone);
            for (auto ns : row[stones[stone][1]])
                bfs(ns);
            for (auto ns : col[stones[stone][0]])
                bfs(ns);
            return 1;
        };
        
        int remained = 0;
        for (int i=0;i<stones.size();++i)
        {
            remained += bfs(i);
        }
        return stones.size() - remained;
    }
};