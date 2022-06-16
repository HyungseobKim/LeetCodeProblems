class Solution {
public:
    int search(vector<int>& nums, int target) {
        int min = 0;
        int max = nums.size();
        
        while (min < max)
        {
            const int mid = (min + max) / 2;
            const int num = nums[mid];
            
            if (num == target)
            {
                return mid;
            }
            
            if (num < target)
            {
                if (min == mid)
                {
                    ++min;
                }
                else
                {
                    min = mid;   
                }
            }
            else
            {
                max = mid;
            }
        }
        
        return -1;
    }
};