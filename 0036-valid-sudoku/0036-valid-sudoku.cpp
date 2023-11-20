class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int y=0;y<board.size();++y)
        {
            for (int x=0;x<board[y].size();++x)
            {
                if (ValidateRow(board, y) && ValidateCol(board, x) && ValidateSub(board, y, x))
                    continue;
                return false;
            }
        }
        
        return true;
    }
    
    bool ValidateRow(vector<vector<char>>& board, int row) {
        vector<int> nums(9, 0);
        for (int i=0;i<9;++i)
        {
            auto c = board[row][i];
            if (c == '.')
                continue;
            if (++nums[c - '0' - 1] > 1)
                return false;
        }
        return true;
    }
    
    bool ValidateCol(vector<vector<char>>& board, int col) {
        vector<int> nums(9, 0);
        for (int i=0;i<9;++i)
        {
            auto c = board[i][col];
            if (c == '.')
                continue;
            if (++nums[c - '0' - 1] > 1)
                return false;
        }
        return true;
    }
    
    bool ValidateSub(vector<vector<char>>& board, int row, int col) {
        vector<int> nums(9, 0);
        row = (row / 3) * 3;
        col = (col / 3) * 3;
        for (int y=0;y<3;++y)
        {
            for (int x=0;x<3;++x)
            {
                auto c = board[row+y][col+x];
                if (c == '.')
                    continue;
                if (++nums[c - '0' - 1] > 1)
                    return false;
            }
        }
        return true;
    }
};