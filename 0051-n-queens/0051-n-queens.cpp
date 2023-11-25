class Solution {
public:
    vector<vector<string>> result;
    vector<string> board;
    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));
        backtrack(board, 0);
        return result;
    }
    
    void backtrack(vector<string>& board, int y)
    {
        if (y == board.size())
        {
            result.push_back(board);
            return;
        }
        
        for (int x=0;x<board.size();++x)
        {
            if (!canPlace({x, y})) continue;
            board[y][x] = 'Q';
            backtrack(board, y + 1);
            board[y][x] = '.';
        }
    }
    
    bool canPlace(pair<int, int> pos)
    {
        auto [cx, cy] = pos;
        for (int y=0;y<cy;++y)
        {
            if (board[y][cx] == 'Q')
                return false;
            auto d = cy - y;
            auto x = cx + d;
            if (x >= 0 && x < board.size() && board[y][x] == 'Q')
                return false;
            x = cx - d;
            if (x >= 0 && x < board.size() && board[y][x] == 'Q')
                return false;
        }
        return true;
    }
};