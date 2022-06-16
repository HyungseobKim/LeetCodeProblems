class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int size = static_cast<int>(nums.size());
        return quickSort(nums, size - k, 0, size);
    }
    
private:
    int quickSort(std::vector<int>& nums, int targetIndex, int first, int last)
    {
        const int pivot = partition(nums, first, last - 1);
        
        if (pivot == targetIndex)
        {
            return nums[pivot];
        }
        
        if (pivot < targetIndex)
        {
            return quickSort(nums, targetIndex, pivot + 1, last);
        }
        
        return quickSort(nums, targetIndex, first, pivot);
    }
    
    int partition(std::vector<int>& nums, int first, int last)
    {
        int i = first;
        const int pivot = nums[last];
        
        for (int j = first; j < last; ++j)
        {
            if (nums[j] < pivot)
            {
                std::swap(nums[i], nums[j]);
                ++i;
            }
        }
        
        std::swap(nums[i], nums[last]);
        return i;
    }    
};