class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> table;

        for (int num : nums)
        {
            if (table.contains(num))
            {
                return true;
            }

            table.insert(num);
        }

        return false;
    }
};