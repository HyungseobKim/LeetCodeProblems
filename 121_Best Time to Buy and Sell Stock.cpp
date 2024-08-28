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
	
	int maxProfit2(vector<int>& prices) {
        const int size = prices.size();
        int highestPrice = prices[size - 1];
        int bestProfit = 0;

        for (int i = size - 2; i >= 0; --i)
        {
            const int price = prices[i];
            highestPrice = std::max(highestPrice, price);
            bestProfit = std::max(bestProfit, highestPrice - price);
        }

        return bestProfit;
    }
};