class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        table = std::vector<int>(amount + 1, -2);
        table[0] = 0;

        std::sort(coins.begin(), coins.end(), [](int a, int b){ return a < b; });
        return coinChange_rec(coins, amount);
    }

private:
    int coinChange_rec(const std::vector<int>& coins, int amount)
    {
        if (table[amount] > -2)
        {
            return table[amount];
        }

        // It can't be greater than the amount because coins are always greater than 0.
        int fewest = amount + 1;

        for (int coin : coins)
        {
            const int remain = amount - coin;
            
            if (remain < 0)
            {
                // We can break because coins are sorted.
                break;
            }

            const int result = coinChange_rec(coins, remain);

            if (result == -1)
            {
                continue;
            }

            fewest = std::min(fewest, result + 1);
        }

        if (fewest == amount + 1)
        {
            // There was no possible way with this amount.
            fewest = -1;
        }

        table[amount] = fewest;
        return fewest;
    }

    std::vector<int> table;
};