struct p {
    int x, y;
    p operator+(const p& rhs)
    {
        return {x + rhs.x, y + rhs.y};
    }
    p operator+=(const p& rhs)
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
};
class Solution {
public:
    int m, n;
    p dir[4] = {{1, 0}, {1, 1}, {-1, 0}, {-1, 1}};
    int getResult(vector<vector<int>>& g, int col)
    {
        p cur = {col, 0};
        p next;
        while (cur.y < m)
        {
            if (g[cur.y][cur.x] > 0)
            {
                next = cur + dir[0];
                if (next.x >= n || g[next.y][next.x] < 0)
                    return -1;
                cur += dir[1];
            }
            else
            {
                next = cur + dir[2];
                if (next.x < 0 || g[next.y][next.x] > 0)
                    return -1;
                cur += dir[3];
            }
        }
        return cur.x;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<int> v(n);
        for (int i=0;i<n;++i)
        {
            v[i] = getResult(grid, i);
        }
        return v;
    }
};