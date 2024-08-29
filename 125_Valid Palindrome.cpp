class Solution {
public:
    bool isPalindrome(string s) {
        const int length = s.length();
        char table[length];

        int index = 0;

        for (const char c : s)
        {
            if (c >= 'a' && c <= 'z')
            {
                table[index] = c;
                ++index;
            }
            else if (c >= 'A' && c <= 'Z')
            {
                table[index] = c - 'A' + 'a';
                ++index;
            }
            else if (c >= '0' && c <= '9')
            {
                table[index] = c;
                ++index;
            }
        }

        for (int index1 = 0, index2 = index - 1; index1 < index2; ++index1, --index2)
        {
            if (table[index1] != table[index2])
            {
                return false;
            }
        }

        return true;
    }
};