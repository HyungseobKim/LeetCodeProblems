class Solution {
public:
    bool isPalindrome(string s) {
        const int length = static_cast<int>(s.length());
        
        auto IsAlphanumeric = [](char c){            
            if (c < '0')
            {
                // not alphanumeric
                return -1;
            }
            
            if (c <= '9')
            {
                // numeric
                return 0;
            }
            
            if (c < 'A')
            {
                // not alphanumeric
                return -1;
            }
            
            if (c <= 'Z')
            {
                // upper letter
                return 1;
            }
            
            if (c < 'a')
            {
                // not alphanumeric
                return -1;
            }
            
            if (c <= 'z')
            {
                // lower letter
                return 2;
            }
            
            // not alphanumeric
            return -1;
        };
        
        for (int begin = -1, end = length; begin + 1 < end;)
        {
            int alphanumeric;
            
            char c1;
            do
            {
                if (begin >= end)
                {
                    return true;
                }
                
                ++begin;
                c1 = s[begin];
                
                alphanumeric = IsAlphanumeric(c1);
            } while (alphanumeric == -1);
            
            if (alphanumeric == 1)
            {
                c1 += ('a' - 'A');
            }
            
            char c2;
            do
            {
                if (begin >= end)
                {
                    return true;
                }
                
                --end;
                c2 = s[end];
                
                alphanumeric = IsAlphanumeric(c2);
            } while (alphanumeric == -1);
            
            if (alphanumeric == 1)
            {
                c2 += ('a' - 'A');
            }
            
            if (c1 != c2)
            {
                return false;
            }
        }
        
        return true;
    }
};