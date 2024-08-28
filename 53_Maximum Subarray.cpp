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
	
	int maxSubArray(vector<int>& nums) {
        const int size = nums.size();
        int index = 0;

        if (nums[0] < 0)
        {
            int biggest_negative = nums[0];
            int negative_index = 1;

            while (negative_index < size)
            {
                const int num = nums[negative_index];
                if (num < 0)
                {
                    biggest_negative = std::max(biggest_negative, num);
                    ++negative_index;
                }
                else
                {
                    break;
                }
            }

            if (negative_index == size)
            {
                return biggest_negative;
            }

            index = negative_index;
        }
        
        int maxSum = nums[index];
        int sum = maxSum;

        for (int i = index + 1; i < size; ++i)
        {
            const int num = nums[i];

            if (num >= 0)
            {
                sum += num;
            }
            else
            {
                maxSum = std::max(maxSum, sum);
                
                int negative_index = i;
                while (negative_index < size)
                {
                    if (nums[negative_index] <= 0)
                    {
                        sum += nums[negative_index];
                    }
                    else
                    {
                        break;
                    }

                    ++negative_index;
                }

                if (sum < 0)
                {
                    sum = 0;
                }

                i = negative_index - 1;
            }
        }

        return std::max(maxSum, sum);
    }
};