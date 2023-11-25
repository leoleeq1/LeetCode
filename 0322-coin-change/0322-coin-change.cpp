class Solution {
public:
    vector<int> memo = vector<int>(10001, 0);
    int coinChange(vector<int>& coins, int amount) {
        for (auto c : coins)
        {
            if (c > 10000) continue;
            memo[c] = 1;
        }
        auto result = dp(coins, amount);
        return result <= 10000 ? result : -1;
    }
    
    int dp(vector<int>& coins, int amount)
    {
        if (amount < 0) return INT_MAX;
        if (amount == 0) return 0;
        if (memo[amount]) return memo[amount];
        
        auto minCoin = INT_MAX;
        for (auto c : coins)
        {
            if (c > amount) continue;
            auto m = dp(coins, amount - c);
            minCoin = min(minCoin, m);
        }
        
        return memo[amount] = minCoin > 10000 ? INT_MAX : minCoin + 1;
    }
};