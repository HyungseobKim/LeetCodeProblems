class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cheapest = prices[0];
        int max_profit = 0;
        
        for (const int price : prices)
        {
            const int profit = price - cheapest;
            if (profit < 0)
            {
                cheapest = price;
            }
            else if (profit > max_profit)
            {
                max_profit = profit;
            }
        }
        
        return max_profit;
    }
};