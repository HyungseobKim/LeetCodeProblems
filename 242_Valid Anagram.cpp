class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
        {
            return false;
        }
        
        int table[26] = {0};
        
        for (const char c : s)
        {
            table[static_cast<int>(c-'a')] += 1;
        }
        
        for (const char c : t)
        {
            table[static_cast<int>(c-'a')] -= 1;
        }
        
        for (const int i : table)
        {
            if (i != 0)
            {
                return false;
            }
        }
        
        return true;
    }
};