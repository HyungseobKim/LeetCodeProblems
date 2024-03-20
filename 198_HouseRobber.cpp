class Solution {
public:
    int rob(vector<int>& nums) {
        size = nums.size();
        table = std::vector<int>(size, -1);

        return rob_rec(nums, 0);
    }

private:
    int rob_rec(const std::vector<int>& nums, int house)
    {
        if (house >= size)
        {
            return 0;
        }

        if (table[house] > -1)
        {
            return table[house];
        }

        const int takeThisHouse = rob_rec(nums, house + 2) + nums[house];
        const int skipThisHouse = rob_rec(nums, house + 1);

        if (takeThisHouse > skipThisHouse)
        {
            table[house] = takeThisHouse;
        }
        else
        {
            table[house] = skipThisHouse;
        }

        return table[house];
    }

    std::vector<int> table;
    int size;
};