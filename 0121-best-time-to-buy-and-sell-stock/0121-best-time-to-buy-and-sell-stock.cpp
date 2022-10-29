class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int maxProfit = 0;
        int profit = 0;
        int min = 10001;
        for (int i=0;i<len;++i)
        {
            if (min > prices[i])
                min = prices[i];
            profit = prices[i] - min;
            if (profit > maxProfit)
                maxProfit = profit;
        }
        
        return maxProfit;
    }
};