class Solution {
public:
    bool canJump(vector<int>& nums) {
        const int end = nums.size() - 1;
        int reachable = 0;
        for (int i = 0; i <= reachable; ++i)
        {
            const int jump = i + nums[i];
            if (jump >= end)
            {
                return true;
            }
            reachable = std::max(jump, reachable);
        }
        return false;
    }
};