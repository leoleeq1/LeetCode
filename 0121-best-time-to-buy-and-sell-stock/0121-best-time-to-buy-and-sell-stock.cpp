class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minPrice = prices[0];
        int sz = prices.size();
        for (int i=0;i<sz;++i)
        {
            profit = max(profit, prices[i] - minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return profit;
    }
};