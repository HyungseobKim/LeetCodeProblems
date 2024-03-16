class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while (i <= j)
        {
            char c1 = s[i];
            int alphanumeric = IsAlphanumeric(c1);

            while (alphanumeric == -1)
            {
                ++i;

                if (i >= j)
                {
                    return true;
                }

                c1 = s[i];
                alphanumeric = IsAlphanumeric(c1);
            }

            if (alphanumeric == 1)
            {
                c1 -= ('A' - 'a');
            }

            char c2 = s[j];
            alphanumeric = IsAlphanumeric(c2);

            while (alphanumeric == -1)
            {
                --j;

                if (j <= i)
                {
                    return true;
                }

                c2 = s[j];
                alphanumeric = IsAlphanumeric(c2);
            }

            if (alphanumeric == 1)
            {
                c2 -= ('A' - 'a');
            }

            if (c1 != c2)
            {
                return false;
            }

            ++i;
            --j;
        }

        return true;
    }

private:
    int IsAlphanumeric (char c)
    {            
        if (c >= 'a' && c <= 'z')
        {
            return 2;
        }

        if (c >= '0' && c <= '9')
        {
            return 0;
        }

        if (c >= 'A' && c <= 'Z')
        {
            return 1;
        }

        return -1;
    };
};