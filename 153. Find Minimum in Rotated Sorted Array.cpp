class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = 0;
        int max = nums.size() - 1;
        
        while (min + 1 < max)
        {
            const int mid = (min + max)/2;
            
            if (nums[min] < nums[mid])
            {
                if (nums[min] < nums[max])
                {
                    return nums[min];
                }
                
                min = mid;
            }
            else
            {
                max = mid;
            }
        }
        
        return std::min(nums[min], nums[max]);
    }
};