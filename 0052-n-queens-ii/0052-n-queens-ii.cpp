class Solution {
public:
    int res = 0;
    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        backtrack(board, 0);
        return res;
    }
    
    void backtrack(vector<vector<bool>>& board, int y)
    {
        if (y == board.size())
        {
            ++res;
            return;
        }
        
        for (int x=0;x<board.size();++x)
        {
            if (!canPlace(board, x, y)) continue;
            board[y][x] = true;
            backtrack(board, y+1);
            board[y][x] = false;
        }
    }
    
    bool canPlace(vector<vector<bool>>& board, int cx, int cy)
    {
        for (int y=0;y<cy;++y)
        {
            if (board[y][cx]) 
                return false;
            auto d = cy - y;
            auto x = cx + d;
            if (x >= 0 && x < board.size() && board[y][x])
                return false;
            x = cx - d;
            if (x >= 0 && x < board.size() && board[y][x])
                return false;
        }
        return true;
    }
};