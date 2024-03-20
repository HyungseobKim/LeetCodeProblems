class Solution {
public:
    int climbStairs(int n) {
        if (n < 2)
        {
            return n;
        }
        
        table = std::vector<int>(n, -1);
        table[0] = 1;
        table[1] = 2;

        return climbStairs_rec(n);
    }

private:
    int climbStairs_rec(int n)
    {
        if (table[n-1] > 0)
        {
            return table[n-1];
        }
        
        const int cases = climbStairs_rec(n - 1) + climbStairs_rec(n - 2);
        table[n-1] = cases;

        return cases;
    }

    std::vector<int> table;
};