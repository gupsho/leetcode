class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size() <= 1)
            return 0;
        int profit = 0, buy = prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            if(buy < prices[i])
                profit += (prices[i] - buy);
            buy = prices[i];
        }
        return profit;
    }
};
