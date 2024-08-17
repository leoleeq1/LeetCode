class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int startColor = image[sr][sc];
        vector<pair<int, int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        queue<pair<int, int>> q;
        
        q.push({sr, sc});
        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();
            
            if (r < 0 || c < 0 || r >= m || c >= n || image[r][c] != startColor || image[r][c] == color)
                continue;
            
            image[r][c] = color;
            for (int i=0;i<4;++i)
            {
                auto [dr, dc] = dirs[i];
                q.push({r+dr, c+dc});
            }
        }
        
        return image;
    }
};