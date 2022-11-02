struct Position {
    int r, c;
};

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rDir[] = {1, -1, 0, 0};
        int cDir[] = {0, 0, 1, -1};
        int start = image[sr][sc];
        int rMax = image.size();
        int cMax = image[0].size();
        
        queue<Position> q;
        q.push({sr, sc});
        
        while (!q.empty())
        {
            Position p = q.front();
            q.pop();
            
            if (p.r >= rMax || p.r < 0 || p.c >= cMax || p.c < 0 || image[p.r][p.c] != start || image[p.r][p.c] == color)
                continue;
            
            image[p.r][p.c] = color;
            
            for (int i=0;i<4;++i)
            {
                q.push({p.r + rDir[i], p.c + cDir[i]});
            }
        }
        
        return image;
    }
};