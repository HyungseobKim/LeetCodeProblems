class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> table;
        const int length = s.length();

        int substring_begin = 0;
        int substring_length = 0;
        int longest = 0;

        for (int i = 0; i < length; ++i)
        {
            const char c = s[i];
            const auto itr = table.find(c);

            if (itr != table.end() && itr->second >= substring_begin)
            {
                longest = std::max(longest, substring_length);

                substring_length -= (itr->second - substring_begin);
                substring_begin = itr->second + 1;
            }
            else
            {
                ++substring_length;
            }

            table[c] = i;
        }

        return std::max(longest, substring_length);
    }
};