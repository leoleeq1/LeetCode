struct t {
    char c;
    int cnt;
    t(char c, int cnt) : c(c), cnt(cnt) {}
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0)
            return tasks.size();

        t maxT(0, 0);
        unordered_map<char, int> m;
        for (auto& task : tasks)
        {
            m[task] += 1;
            if (maxT.c == task)
                maxT.cnt += 1;
            else if (maxT.cnt < m[task])
            {
                maxT.c = task;
                maxT.cnt = m[task];
            }
        }
        
        int gaps = maxT.cnt - 1;
        int emptySpace = n * gaps;
        int extra = 0;
        for (auto& task : m)
        {
            if (task.first != maxT.c)
            {
                if (task.second == maxT.cnt)
                {
                    emptySpace -= task.second - 1;
                    extra += 1;
                }
                else
                    emptySpace -= task.second;
                if (emptySpace <= 0)
                    return tasks.size();
            }
        }
        return maxT.cnt + n * (maxT.cnt - 1) + extra;
    }
};