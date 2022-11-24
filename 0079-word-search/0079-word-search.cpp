class Solution {
public:
    int m,n;
    int d[4][2] = {{1,0}, {-1,0},{0,1},{0,-1}};
    bool visited[6][6] = {false,};
    bool findWord(vector<vector<char>>& board, const string& word, int i, int r, int c)
    {
        if (r < 0 || c < 0 || r >= m || c >= n || visited[r][c] || board[r][c] != word[i])
            return false;
        if (i == (word.length()-1))
            return true;
        
        visited[r][c] = true;
        for (int j=0;j<4;++j)
        {
            if (findWord(board, word, i+1, r+d[j][0], c+d[j][1]))
                return true;
        }
        visited[r][c] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (int r=0;r<m;++r)
        {
            for (int c=0;c<n;++c)
            {
                if (findWord(board, word, 0, r, c))
                    return true;
            }
        }
        return false;
    }
};