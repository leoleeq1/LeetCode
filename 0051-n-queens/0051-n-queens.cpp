class Solution {
public:
    vector<vector<string>> result;
    vector<pair<int, int>> placed;
    vector<vector<string>> solveNQueens(int n) {
        backtrack(n, {-1, -1});
        return result;
    }
    
    void backtrack(int n, pair<int, int> pos)
    {
        if (placed.size() == n)
        {
            vector<string> sub;
            for (int i=0;i<n;++i)
            {
                auto [x, y] = placed[i];
                string s(n, '.');
                s[x] = 'Q';
                sub.push_back(s);
            }
            result.push_back(sub);
            return;
        }
        
        auto [cx, cy] = pos;
        for (int y=cy+1;y<n;++y)
        {
            for (int x=0;x<n;++x)
            {
                if (!canPlace({x, y})) continue;
                placed.push_back({x, y});
                backtrack(n, {x ,y});
                placed.pop_back();
            }
        }
    }
    
    bool canPlace(pair<int, int> pos)
    {
        return placed.size() == 0 || !any_of(placed.begin(), placed.end(), [&](auto p) {
            auto [x, y] = pos;
            auto [px, py] = p;
            return x == px || y == py || (abs(x - px) == abs(y - py));
        });
    }
};