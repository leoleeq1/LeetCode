class Solution {
public:
    int amounts[10001];
    int dp(vector<int>& coins, int amount)
    {
        if (amount < 0)
            return 10001;
        if (amounts[amount] >= 0)
            return amounts[amount];
        int m = 10001;
        for (int n=0;n<coins.size();++n)
        {
            m = min(m,dp(coins,amount - coins[n]));
        }
        return amounts[amount] = 1 + m;
    }
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        memset(amounts, -1, sizeof(amounts));
        amounts[0] = 0;
        
        int result = dp(coins, amount);
        return result > 10000 ? -1 : result;
    }
};