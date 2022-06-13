class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int size = static_cast<int>(nums.size());
        std::vector<bool> table(size, false);
        
        // Record all valid numbers.
        for (const int num : nums)
        {
            if (num > 0 && num - 1 < size)
            {
                table[num-1] = true;
            }
        }
        
        // Find the first false.
        for (int i = 0; i < size; ++i)
        {
            if (table[i] == false)
            {
                return i + 1;
            }
        }
        
        // All numbers are consecutive.
        return size + 1;
    }
};