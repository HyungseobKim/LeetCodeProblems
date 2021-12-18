class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> result(2);
        std::unordered_map<int, int> table;
        const int size = static_cast<int>(nums.size());
        
        for (int i = 0; i < size; ++i)
        {
            const int curr = nums[i];
            std::unordered_map<int, int>::const_iterator complement = table.find(target - curr);
            
            if (complement == table.end())
                table[curr] = i;
            else
            {
                result[0] = i;
                result[1] = complement->second;
                return result;
            }
        }
        
        return result;
    }
};