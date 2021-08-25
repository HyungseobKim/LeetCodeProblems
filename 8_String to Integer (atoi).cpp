class Solution {
public:
    int myAtoi(string s) {
        const int size = s.size();
        
        int sign = 1;
        int index = 0;
        
        // Skip leading whitespaces.
        while (index < size)
        {
            if (s[index] == ' ')
                ++index;
            else
                break;
        }
        
        // Check sign.
        char current = s[index];
        if (current == '-')
        {
            sign = -1;
            ++index;
        }
        else if (current == '+')
            ++index;
        else if (current < '0' || current > '9')
            return 0;
        
        // Skip 0s.
        while (index < size)
        {
            if (s[index] == '0')
                ++index;
            else
                break;
        }
        
        const int start = index;
        int end = index;
        
        // Find length of digits.
        while (end < size)
        {
            current = s[end];
            
            if (current < '0' || current > '9')
                break;
            else
                ++end;
        }
        
        const int length = end - start;
        
        // If there are more than 10 digits, it definitely over the range.
        if (length > 10)
            return ReturnMax(sign);
        
        // Read numbers except 10th digit.
        int result = 0;
        int figure = 1;
        const int safe = start + (length < 10 ? 0 : 1);
        
        for (int i = end-1; i >= safe; --i)
        {
            result += (s[i] - '0') * figure;
            figure *= 10;
        }
        
        // Guaranteed to be inside range.
        if (length < 10)
            return sign * result;
        
        const int lastDigit = s[start] - '0';
        if (lastDigit > 2)
            return ReturnMax(sign);
        
        if (sign > 0)
        {
            if (max - 1 - result < lastDigit * figure)
                return max;
        }
        else
        {
            if (max - result < lastDigit * figure)
                return -max-1;
        }
        
        return sign * (result + lastDigit * figure);
    }
    
    int ReturnMax(int sign)
    {
        if (sign > 0)
                return max;
        else
            return -max-1;
    }
    
private:
    const static int max = 2147483647;
};