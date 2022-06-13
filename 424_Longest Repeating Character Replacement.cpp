class Solution {
public:
    int characterReplacement(string s, int k) {
        int table[26] = {0};
        
        // The number of the dominant character in the window.
        int numDominantChar = 0;
        int best = 0;
        
        const int size = static_cast<int>(s.length());
        
        // Always try to expand the window.
        for (int left = 0, right = 0; right < size; ++right)
        {
            const int index = static_cast<int>(s[right] - 'A');
            table[index] += 1;
            
            const int length = right - left + 1;
            
            if (table[index] > numDominantChar)
            {
                // New character becomes the dominant character.
                // It means the number of characters that need to be replace doesn't change.
                // Therefore, the current window is valid.
                numDominantChar = table[index];
            }
            else if (length - numDominantChar > k)
            {
                // The current window is not valid.
                // We must increase the left to make the window valid.
                // However, we don't need to update the number of the dominant character.
                // The reason is that won't affect the best because we just shrank the window.
                table[static_cast<int>(s[left] - 'A')] -= 1;
                ++left;
                
                continue;
            }
            
            // If we successfully expand the window, it increases the best.
            best = length;
        }
        
        return best;
    }
};