class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int size = nums.size();

        for (int i = 0; i < size; ++i)
        {
            if (nums[i] < 0)
            {
                nums[i] = 0;
            }
        }

        for (int i = 0; i < size; ++i)
        {
            const int num = std::abs(nums[i]);
            const int index = num - 1;

            if (index >= 0 && index < size)
            {
                if (nums[index] == 0)
                {
                    nums[index] = -num;
                }
                else
                {
                    nums[index] = -std::abs(nums[index]);
                }
            }
        }

        for (int i = 0; i < size; ++i)
        {
            if (nums[i] >= 0)
            {
                return i + 1;
            }
        }

        return size + 1;
    }
};

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