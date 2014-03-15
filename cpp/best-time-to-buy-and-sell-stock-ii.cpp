class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        if(prices.size() <= 1)
            return profit;
            
        int buyPrice = prices[0];
        for(int i = 1; i < prices.size(); i ++)
        {
            if(buyPrice > prices[i])
                buyPrice = prices[i];
            else
            {
                profit += prices[i] - buyPrice;
                buyPrice = prices[i];
            }
        }
        return profit;
    }
};
