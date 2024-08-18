class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0)
        {
            return {newInterval};
        }
        vector<vector<int>> answer;
        auto first = find_if(intervals.begin(), intervals.end(), [&](auto& i) { return i[1] >= newInterval[0]; });
        auto last = find_if(intervals.rbegin(), intervals.rend(), [&](auto& i) { return i[0] <= newInterval[1]; });
                
        copy(intervals.begin(), first, back_inserter(answer));
        answer.push_back({min(first == intervals.end() ? INT_MAX : (*first)[0], newInterval[0]), max(last == intervals.rend() ? INT_MIN : (*last)[1], newInterval[1])});
        copy(intervals.begin() + (intervals.size() - distance(intervals.rbegin(), last)), intervals.end(), back_inserter(answer));
        return answer;
    }
};