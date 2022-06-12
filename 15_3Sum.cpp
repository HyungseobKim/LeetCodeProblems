class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> answer;
        std::unordered_map<int, std::vector<int>> table;
        
        const int size = nums.size();
        for (int i = 0; i < size; ++i)
        {
            const int num = nums[i];
            
            if (table.find(num) == table.end())
            {
                table[num] = std::vector<int>();
            }
            
            table[num].push_back(i);
        }
        
        for (int i = 0; i < size; ++i)
        {
            const int num1 = nums[i];
            
            if (table[num1].front() != i)
            {
                // We already used this number.
                continue;
            }
            
            for (int j = i + 1; j < size; ++j)
            {
                const int num2 = nums[j];
                
                if (num1 == num2)
                {
                    if (table[num2][1] != j)
                    {
                        // We already used this number.
                        continue;
                    }
                }
                else if (table[num2].front() != j)
                {
                    // We already used this number.
                    continue;
                }
                
                const int num3 = -(num1 + num2);
                
                if (table.find(num3) == table.end())
                {
                    // There is no such a number that can make the sum zero.
                    continue;
                }
                
                const std::vector<int>& k = table[num3];
                
                if (k.front() < i)
                {
                    // We already checked triplets started with this number.
                    continue;
                }
                
                if (num3 == num1 || num3 == num2)
                {
                    if (num3 == 0)
                    {
                        // Special case: num1=num2=num3=0.
                        continue;
                    }
                    
                    if (num3 == num1)
                    {
                        bool duplicate = false;
                        
                        for (const int index : k)
                        {
                            if (index > i && index < j)
                            {
                                duplicate = true;
                                break;
                            }
                        }
                        
                        if (duplicate)
                        {
                            // There was the same number between i and k.
                            continue;
                        }
                    }
                    
                    if (k.back() <= j)
                    {
                        continue;
                    }
                }
                else
                {
                    if (k.front() <= j)
                    {
                        continue;
                    }
                }
                
                answer.push_back(std::vector<int>{num1, num2, num3});
            }
        }
        
        // Special case: num1=num2=num3=0.
        if (table.find(0) != table.end())
        {
            if (table[0].size() >= 3)
            {
                answer.push_back(std::vector<int>{0, 0, 0});
            }
        }
        
        return answer;
    }
};