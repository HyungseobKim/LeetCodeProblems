class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        answer.push_back(std::vector<int>());
        
        subsets_rec(nums, nums.size() - 1);
        
        return answer;
    }
    
private:
    void subsets_rec(const std::vector<int>& nums, int indexLast)
    {
        const int num = nums[indexLast];
        
        if (indexLast == 0)
        {
            answer.push_back(std::vector<int>(1, num));
            return;
        }
        
        subsets_rec(nums, indexLast - 1);
        
        const int size = answer.size();
        
        for (int i = 0; i < size; ++i)
        {
            answer.push_back(answer[i]);
            answer.back().push_back(num);
        }
    }
    
private:
    std::vector<std::vector<int>> answer;
};