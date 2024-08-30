class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        int total = 1;
        for (int i = 0; i < k; ++i)
        {
            total *= (n-i);
            total /= (i+1);
        }
        
        answer = std::vector<std::vector<int>>(total, std::vector<int>(k));
        index = 0;

        std::vector<int> nums(k, 0);
        combine_rec(1, n, k, nums);

        return answer;
    }

private:
    void combine_rec(int start, int n, int k, std::vector<int>& nums)
    {
        if (k == 1)
        {
            for (int i = start; i <= n; ++i)
            {
                answer[index] = nums;
                answer[index][0] = i;
                ++index;
            }
            return;
        }

        for (int i = start; i <= n; ++i)
        {
            nums[k-1] = i;
            combine_rec(i+1, n, k-1, nums);
        }
    }

    std::vector<std::vector<int>> answer;
    int index;
};