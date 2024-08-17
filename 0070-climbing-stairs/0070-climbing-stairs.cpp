class Solution {
public:
    int dp[46] = {0,};
    int climbStairs(int n) {
        if (n < 0) return 0;
        if (dp[n] != 0) return dp[n];
        if (n <= 2) return dp[n] = n;
        return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};