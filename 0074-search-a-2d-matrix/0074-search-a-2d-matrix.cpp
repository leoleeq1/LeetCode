class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = matrix[0].size();
        if (target < matrix[0][0])
            return false;
        
        int sr = 0;
        int er = r - 1;
        int mr;
        while (true)
        {
            mr = (sr + er) / 2;
            if (target >= matrix[mr][0] && (mr == (r-1) || target < matrix[mr+1][0]))
                break;
            else if (target < matrix[mr][0])
                er = mr - 1;
            else
                sr = mr + 1;
        }
        
        int sc = 0;
        int ec = c - 1;
        int mc;
        while (sc <= ec)
        {
            mc = (sc + ec) / 2;
            if (target == matrix[mr][mc])
                return true;
            else if (target > matrix[mr][mc])
                sc = mc + 1;
            else
                ec = mc - 1;
        }
        return false;
    }
};