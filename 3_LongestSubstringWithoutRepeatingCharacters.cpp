class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> table;

        int subStringBegin = 0;
        int length = 0;
        int longest = 0;

        const int end = s.length();

        for (int i = 0; i < end; ++i)
        {
            const char c = s[i];

            if (table.find(c) == table.end() || table[c] < subStringBegin)
            {
                ++length;
            }
            else
            {
                longest = std::max(longest, length);

                length -= (table[c] - subStringBegin);
                subStringBegin = table[c] + 1;
            }

            table[c] = i;
        }

        return std::max(longest, length);
    }
};
