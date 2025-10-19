class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> table = std::vector<int>(amount + 1, amount + 1);
        table[0] = 0;

        for (int value = 1; value <= amount; ++value)
        {
            for (const int coin : coins)
            {
                const int remain = value - coin;
                if (remain >= 0)
                {
                    table[value] = std::min(table[value], table[remain] + 1);
                }
            }
        }

        if (table[amount] == amount + 1)
        {
            return -1;
        }

        return table[amount];
    }
};