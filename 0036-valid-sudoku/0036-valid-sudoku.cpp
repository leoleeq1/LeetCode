class Solution {
public:
    bool isValidBox(vector<vector<char>>& board, int r, int c)
    {
        unordered_set<char> s;
        for (int y=0;y<3;++y)
        {
            for (int x=0;x<3;++x)
            {
                char n = board[r+y][c+x];
                if (n == '.') continue;
                if (s.count(n) > 0)
                    return false;
                s.insert(n);     
            }
        }
        return true;
    }
    bool isValidCol(vector<vector<char>>& board, int c)
    {
        unordered_set<char> s;
        for (int i=0;i<9;++i)
        {
            char n = board[i][c];
            if (n == '.') continue;
            if (s.count(n) > 0)
                return false;
            s.insert(n);
        }
        return true;
    }
    bool isValidRow(vector<vector<char>>& board, int r)
    {
        unordered_set<char> s;
        for (int i=0;i<9;++i)
        {
            char n = board[r][i];
            if (n == '.') continue;
            if (s.count(n) > 0)
                return false;
            s.insert(n);
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0;i<9;++i)
        {
            if (!isValidRow(board, i) || !isValidCol(board, i))
                return false;
        }
        
        for (int r=0;r<9;r+=3)
        {
            for (int c=0;c<9;c+=3)
            {
                if (!isValidBox(board, r, c))
                    return false;
            }
        }
        return true;
    }
};