class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0)
            return vector<vector<int>>(1, newInterval);
        
        vector<vector<int>> v;
        bool inserted = false;
        int n = intervals.size();
        for (int i=0;i<n;++i)
        {
            if (intervals[i][0] > newInterval[1])
            {
                if (!inserted)
                {
                    inserted = true;
                    v.push_back(newInterval);
                }
                v.push_back(intervals[i]);
            }
            else if (intervals[i][1] < newInterval[0])
                v.push_back(intervals[i]);
            else
            {
                int j = i;
                while (j < n && intervals[j][0] < newInterval[1])
                    ++j;
                if (j == n || intervals[j][0] > newInterval[1])
                    --j;
                v.push_back({min(intervals[i][0], newInterval[0]), max(intervals[j][1], newInterval[1])});
                inserted = true;
                i = j;
            }
        }
        if (!inserted)
            v.push_back(newInterval);
        return v;
    }
};