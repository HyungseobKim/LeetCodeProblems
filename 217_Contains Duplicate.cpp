class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> table;
        
        for (const int num : nums)
        {
            if (table.find(num) != table.end())
            {
                return true;
            }
            
            table.insert(num);
        }
        
        return false;
    }
};