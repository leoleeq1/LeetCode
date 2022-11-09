struct p {
    int x, y;
    p operator+(const p& rhs)
    {
        return {x + rhs.x, y + rhs.y};
    }
};

class Solution {
public:
    p dir[4] = {{1,0}, {0, 1}, {-1,0}, {0,-1}};
    p cur = {0, 0};
    int m, n;
    int cd = 0;
    void changeDir(int& i)
    {
        i = i > 2 ? 0 : i+1;
    }
    bool moveNext(vector<vector<int>>& mat)
    {
        mat[cur.y][cur.x] = 1000;
        p next;
        for (int i=0;i<4;++i)
        {
            next = cur + dir[cd];
            if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m || mat[next.y][next.x] == 1000)
            {
                changeDir(cd);
            }
            else
            {
                cur = next;
                return true;
            }
        }
        return false;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        vector<int> v;
        do
        {
            v.push_back(matrix[cur.y][cur.x]);
        }
        while (moveNext(matrix));
        return v;
    }
};