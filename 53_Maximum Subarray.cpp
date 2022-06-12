class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int size = static_cast<int>(nums.size());
        int index = 0;
        
        while (index < size && nums[index] < 0)
        {
            ++index;
        }
        
        if (index == size)
        {
            int biggest = nums[0];
            
            for (int i = 1; i < size; ++i)
            {
                if (nums[i] > biggest)
                {
                    biggest = nums[i];;
                }
            }
            
            return biggest;
        }
        
        int sum = nums[index++];
        int best = sum;
        
        for (int i = index; i < size; ++i)
        {
            const int num = nums[i];
            
            if (num < 0)
            {
                if (sum > best)
                {
                    best = sum;
                }
                
                if (sum + num > 0)
                {
                    sum += num;
                }
                else
                {
                    sum = 0;
                }
            }
            else
            {
                sum += num;
            }
        }
        
        if (sum > best)
        {
            return sum;
        }
        
        return best;
    }
};