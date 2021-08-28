class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        const int size = arr.size() - 1;
        if (size == 0)
            return 1;
        
        int index = 0;
        
        // Ignore all the same numbers at the front of the array.
        while (index < size)
        {
            if (arr[index] == arr[index+1])
                ++index;
            else
                break;
        }
        
        // All numbers are the same.
        if (index == size)
            return 1;
        
        // They are different.
        bool test = arr[index] < arr[index+1];
        
        // We already found that there are two different numbers.
        int length = 2;
        int best = 2;
        
        while (index < size)
        {
            const int curr = arr[index];
            const int next = arr[index+1];
            
            // Subarray ended by the same numbers.
            if (curr == next)
            {
                // Store best.
                if (length > best)
                    best = length;
                
                // Ignore all the same numbers.
                while (index < size)
                {
                    if (arr[index] == arr[index+1])
                        ++index;
                    else
                        break;
                }
                
                // Last elements of the array.
                if (index == size)
                    return best;
                
                // They are different.
                test = arr[index] < arr[index+1];
                length = 2;
            }
            else
            {
                // Subarray ended.
                if (curr < next == test)
                {
                    // Store best.
                    if (length > best)
                        best = length;
                    
                    length = 2;
                }
                else // Still turbulent.
                {
                    ++length; // Increase length of the subarray.
                    test = !test; // Reverse the test.
                }
            }
            
            ++index;
        }
        
        if (length > best)
            return length;
        
        return best;
    }
};