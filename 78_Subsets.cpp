class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        size = nums.size();

        std::vector<int> base;
        answer.push_back(base);

        subsets_rec(nums, base, 0);
        return answer;
    }

private:
    void subsets_rec(const std::vector<int>& nums, std::vector<int>& base, int begin)
    {
        for (int i = begin; i < size; ++i)
        {
            base.push_back(nums[i]);
            answer.push_back(base);

            subsets_rec(nums, base, i + 1);

            base.pop_back();
        }
    }

    std::vector<std::vector<int>> answer;
    int size;
};