class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> result(2);

        std::unordered_map<int, int> table;
        table[nums[0]] = 0;

        const int size = static_cast<int>(nums.size());

        for (int i = 1; i < size; ++i)
        {
            const int num = nums[i];
            std::unordered_map<int, int>::const_iterator complement = table.find(target - num);

            if (complement == table.end())
            {
                table[num] = i;
            }
            else
            {
                result[0] = complement->second;
                result[1] = i;

                return result;
            }
        }

        return result;
    }
};