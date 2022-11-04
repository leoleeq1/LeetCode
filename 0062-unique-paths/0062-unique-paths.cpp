class Solution {
public:
    int r, c;
    int path[10000];
    int getPath(int m, int n)
    {
        if (m >= r || n >= c)
            return 0;
        if (path[m * c + n] < 0)
            return path[m * c + n] = getPath(m + 1, n) + getPath(m, n + 1);
        return path[m * c + n];
    }
    int uniquePaths(int m, int n) {
        if (m == 1 && n == 1)
            return 1;
        memset(path, 0xff, sizeof(path));
        r = m;
        c = n;
        path[m * n - 1] = 0;
        path[max(m * n - 2, 0)] = 1;
        path[max((m - 1) * n - 1, 0)] = 1;
        return getPath(0, 0);
    }
};