class Solution {
public:
    string longestPalindrome(string s) {
        const int length = s.length();
        std::string longest;

        for (int i = 1; i < length; ++i)
        {
            int left = i - 1;
            int right = i + 1;

            while (left >= 0 && right < length)
            {
                if (s[left] == s[right])
                {
                    --left;
                    ++right;
                }
                else
                {
                    break;
                }
            }

            if (right - left - 1 > longest.length())
            {
                longest = s.substr(left + 1, right - left - 1);
            }

            left = i - 1;
            right = i;

            while (left >= 0 && right < length)
            {
                if (s[left] == s[right])
                {
                    --left;
                    ++right;
                }
                else
                {
                    break;
                }
            }

            if (right - left - 1 > longest.length())
            {
                longest = s.substr(left + 1, right - left - 1);
            }
        }

        if (longest.length() == 0)
        {
            longest = s[0];
        }

        return longest;
    }
};