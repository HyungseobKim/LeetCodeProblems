class Solution {
public:
    int rob(vector<int>& nums) {
        const int size = static_cast<int>(nums.size());
        
        table = std::vector<int>(size+2, -1);
        table[0] = 0;
        table[1] = 0;
        
        return robRec(nums, size-1);
    }
    
private:
    int robRec(std::vector<int>& nums, int index)
    {
        if (table[index+2] >= 0)
            return table[index+2];
        
        const int robThis = robRec(nums, index-2) + nums[index];
        const int notThis = robRec(nums, index-1);
        
        table[index+2] = std::max(robThis, notThis);
        return table[index+2];
    }
    
private:
    std::vector<int> table;
};