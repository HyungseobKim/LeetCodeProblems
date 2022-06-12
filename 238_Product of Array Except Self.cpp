class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int size = static_cast<int>(nums.size());
        std::vector<int> answer(size, 1);
        
        for (int i = 1; i < size; ++i)
        {
            answer[i] = answer[i-1] * nums[i-1];
        }
        
        int reverse = nums[size-1];
        
        for (int i = size-2; i >= 0; --i)
        {
            answer[i] *= reverse;
            reverse *= nums[i];
        }
        
        return answer;
    }
};