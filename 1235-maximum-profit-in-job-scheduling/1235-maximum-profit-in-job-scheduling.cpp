struct job {
    int start, end, profit;
    bool operator<(const job& rhs)
    {
        return start < rhs.start;
    }
    bool operator<(int i)
    {
        return start < i;
    }
};
class Solution {
public:
    unordered_map<int, int> cache;
    int dp(vector<job>& jobs, int i)
    {
        if (cache.find(i) != cache.end())
            return cache[i];
        int j = lower_bound(jobs.begin(), jobs.end(), i) - jobs.begin();
        if (j < 0 || j >= jobs.size())
            return 0;
        int start = jobs[j].start;
        int end = jobs[j].end;
        int mxm = jobs[j].profit;
        while(j < jobs.size() && jobs[j].start < end)
        {
            int profit;
            if (cache.find(jobs[j].start) != cache.end())
                profit = cache[jobs[j].start];
            else
                profit = jobs[j].profit + dp(jobs, jobs[j].end);
            mxm = max(mxm, profit);
            ++j;
        }
        cache[start] = mxm;
        cache[i] = mxm;
        return mxm;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<job> jobs;
        for (int i=0;i<startTime.size();++i)
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        sort(jobs.begin(), jobs.end());
        return dp(jobs, 0);
    }
};