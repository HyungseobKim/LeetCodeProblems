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
	
	int search(vector<int>& nums, int target) {
        int min = 0;
        int max = nums.size() - 1;
        int pivot = 0;

        // Find the pivot.
        while (min < max)
        {
            pivot = (min + max) / 2;

            if (pivot == min)
            {
                break;
            }

            const int num = nums[pivot];
            const int num_max = nums[max];
            
            if (num < num_max)
            {
                max = pivot;
            }
            else if (num > num_max)
            {
                min = pivot;
            }
        }

        if (nums[min] < nums[max])
        {
            pivot = min;
        }
        else
        {
            pivot = max;
        }

        // Set the range for the search using the pivot.
        max = nums.size();
        int mid = max / 2;

        if (target == nums[mid])
        {
            return mid;
        }
        else if (target < nums[mid])
        {
            if (pivot < mid)
            {
                min = pivot;
                max = mid; 
            }
            else
            {
                if (nums[0] <= target)
                {
                    min = 0;
                    max = mid;
                }
                else
                {
                    min = pivot;
                }
            }
        }
        else
        {
            if (mid < pivot)
            {
                min = mid;
                max = pivot;
            }
            else
            {
                if (target <= nums[max-1])
                {
                    min = mid;
                }
                else
                {
                    min = 0;
                    max = pivot;
                }
            }
        }

        // Do the normal binary search.
        while (min < max)
        {
            mid = (min + max) / 2;
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