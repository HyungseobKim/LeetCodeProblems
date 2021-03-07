class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int end = nums.size() - 1;
        
        int index = 0;
        int prev = 0;
        
        while (index < end)
        {
            const int num = nums[index];
            
            if (num == 0) // Need to go back
            {
                int max = 0;
                
                for (int i = prev; i < index; ++i)
                {
                    const int jump = i + nums[i];
                    if (jump > max)
                        max = jump;
                }
                
                if (max <= index)
                    return false;
                
                prev = index+1;
                index = max;
            }
            
            index += num;
        }
        
        return true;
    }
};