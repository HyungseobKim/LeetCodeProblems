class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int table[26] = {0};
        
        for (const char c : magazine)
        {
            table[static_cast<int>(c - 'a')] += 1;
        }
        
        for (const char c : ransomNote)
        {
            const int index = static_cast<int>(c - 'a');
            
            if (table[index] == 0)
            {
                return false;
            }
            
            table[index] -= 1;
        }
        
        return true;
    }
};