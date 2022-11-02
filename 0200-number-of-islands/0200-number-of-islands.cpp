struct Pos {
    int x, y;
    Pos(int x, int y) : x(x), y(y) {}
    Pos operator+(const Pos& rhs)
    {
        return Pos(x + rhs.x, y + rhs.y);
    }
};
class Solution {
public:
    Pos dir[4] = {Pos(1, 0), Pos(-1, 0), Pos(0, 1), Pos(0, -1)};
    int m;
    int n;
    bool isAnIsland(vector<vector<char>>& map, Pos start)
    {
        if (start.x < 0 || start.y < 0 || start.x >= n || start.y >=m || map[start.y][start.x] != '1')
            return false;
        
        map[start.y][start.x] = '0';
        for (int i=0;i<4;++i)
        {
            isAnIsland(map, start + dir[i]);
        }
        return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int cnt = 0;
        
        for (int y=0;y<m;++y)
        {
            for (int x=0;x<n;++x)
            {
                if (isAnIsland(grid, Pos(x, y)))
                    ++cnt;
            }
        }
        return cnt;
    }
};