class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> table;
        const int size = static_cast<int>(s.length());
        
        int best = 0;
        int length = 0;
        int min = 0; // Current starting point of length.
        
        for (int i = 0; i < size; ++i)
        {
            const char curr = s[i];
            
            auto repeat = table.find(curr);
            
            if (repeat == table.end() || repeat->second < min)
            {
                ++length;
                table[curr] = i;
            }
            else // when we find repeating character
            {
                if (length > best)
                    best = length;
                
                length = i - repeat->second;
                min = repeat->second + 1;
                repeat->second = i;
            }
        }
        
        if (length > best)
            return length;
        
        return best;
    }
};
