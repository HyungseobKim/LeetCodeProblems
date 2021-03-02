class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        const int size = nums.size();
        
        if (!k)
        {
            for (int i = 0; i < size - 1; i++)
            {
                if (nums[i]) continue;
                if (nums[i+1]) ++i;
                else return true;
            }
            
            return false;
        }
        
        for (int i = 0; i < size - 1; i++)
        {
            int sum = nums[i];
            
            for (int j = i + 1; j < size; j++)
            {
                sum += nums[j];
                if (sum % k == 0) return true;
            }
        }
        
        return false;
    }
};