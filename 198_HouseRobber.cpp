class Solution {
public:
    int rob(vector<int>& nums) {
        table = std::vector<int>(nums.size() + 1, -2);
        table[0] = 0;
        table[1] = nums[0];

        return rob_rec(nums, nums.size());
    }

private:
    int rob_rec(const std::vector<int>& nums, int last)
    {
        if (table[last] == -2)
        {
            table[last] = std::max(rob_rec(nums, last - 1), nums[last - 1] + rob_rec(nums, last - 2));
        }

        return table[last];
    }

    std::vector<int> table;
};