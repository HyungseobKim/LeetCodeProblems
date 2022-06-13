class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::map<char, int>, int> table;
        
        std::vector<std::vector<std::string>> answer;
        int index = 0;
        
        for (const std::string& str : strs)
        {
            std::map<char, int> counts;
            
            for (const char c : str)
            {
                counts[c - 'a'] += 1;
            }
            
            bool assigned = false;
            const int size = table.size();
            
            if (table.find(counts) == table.end())
            {
                table[counts] = index++;
                answer.push_back(std::vector<std::string>(1, str));
            }
            else
            {
                answer[table[counts]].push_back(str);
            }
        }
        
        return answer;
    }
};