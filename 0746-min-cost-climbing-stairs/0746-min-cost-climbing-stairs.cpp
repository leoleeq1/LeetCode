class Solution {
public:
    int steps[1001];
    int calcMin(vector<int>& cost, int n)
    {
        if (n <= 1)
            return steps[n];
        if (steps[n] == -1)
            return steps[n] = min(calcMin(cost, n - 1), calcMin(cost, n - 2)) + cost[n];
        return steps[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(steps, 0xff, sizeof(steps));
        steps[0] = cost[0];
        steps[1] = cost[1];
        cost.push_back(0);
        return calcMin(cost, n);
    }
};