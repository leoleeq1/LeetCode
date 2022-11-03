class Solution {
public:
    int steps[46] = {0, 1, 2,};
    int climbStairs(int n) {
        if (n <= 2)
            return steps[n];
        if (steps[n] == 0)
            return steps[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return steps[n];
    }
};