class Solution {
public:
    int getMaxPrice(vector<int>& prices, int s)
    {
        int len = prices.size();
        int maxPrice = -1;
        for (;s<len;++s)
            maxPrice = maxPrice < prices[s] ? prices[s] : maxPrice;
        return maxPrice;
    }
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int len = prices.size();
        int maxPrice;
        int min = 10001;
        for (int i=0;i<len-1;++i)
        {
            if (min <= prices[i])
                continue;
            min = prices[i];
            maxPrice = getMaxPrice(prices, i+1);
            int profit = maxPrice - min;
            maxProfit = maxProfit < profit ? profit : maxProfit;
        }
        
        return maxProfit;
    }
};