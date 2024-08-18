class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        queue<pair<int,int>> q;
        
        for (int r=0;r<m;++r)
        {
            for (int c=0;c<n;++c)
            {
                if (mat[r][c] == 0) q.push({r, c});
                else mat[r][c] = -1;
            }
        }
        
        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();
            for (int i=0;i<4;++i)
            {
                auto [dr, dc] = dirs[i];
                auto nr = r + dr;
                auto nc = c + dc;
                if (nr < 0 || nc < 0 || nr >= m || nc >= n || mat[nr][nc] != -1) continue;
                mat[nr][nc] = mat[r][c] + 1;
                q.push({nr, nc});
            }
        }
        return mat;
    }
};