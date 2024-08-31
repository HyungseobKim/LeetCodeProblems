class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)
        {
            return 1;
        }

        table = std::vector<int>(n + 1, -1);
        table[1] = 1;
        table[2] = 2;

        return climbStairs_rec(n);
    }

private:
    int climbStairs_rec(int n)
    {
        if (table[n] == -1)
        {
            table[n] = climbStairs_rec(n - 1) + climbStairs_rec(n - 2);
        }

        return table[n];
    }

    std::vector<int> table;
};