class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int size = nums.size();
        int index = 0;
        
        while (index < size && nums[index] == 0)
            ++index;
        
        for (int i = index + 1; i < size; ++i)
        {
            if (nums[i] == 0)
            {
                std::swap(nums[i], nums[index]);
                ++index;
            }
        }
        
        while (index < size && nums[index] != 2)
            ++index;
        
        for (int i = index + 1; i < size; ++i)
        {
            if (nums[i] == 1)
            {
                std::swap(nums[i], nums[index]);
                ++index;
            }
        }
    }
};