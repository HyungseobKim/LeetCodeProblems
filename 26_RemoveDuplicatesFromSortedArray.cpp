class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        auto last = std::unique(nums.begin(), nums.end());
        
        return last - nums.begin();
    }
};