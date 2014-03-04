class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        if(len < 2)
            return 0;
        int maxPrices[len];
        maxPrices[len-1] = prices[len-1];
        for(int i = len-2; i>=0; i--)
        {
            if(maxPrices[i+1] >= prices[i])
                maxPrices[i] = maxPrices[i+1];
            else
                maxPrices[i] = prices[i];
        }
        
        int profit = 0, maxProf = 0;
        for(int i = 0; i< len; i++)
        {
            profit = maxPrices[i] - prices[i];
            if(profit > maxProf)
                maxProf = profit;
        }
        
        return maxProf;
        
    }
};
