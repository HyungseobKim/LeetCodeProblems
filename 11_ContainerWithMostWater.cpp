class Solution {
public:
    int maxArea(vector<int>& height) {
        const int size = static_cast<int>(height.size());
        
        int largest = 0;
        int first = height[0];
        std::pair<int, int> highest = std::make_pair(first, 0);
        
        // Find max height during first iteration
        for (int i = 1; i < size; ++i)
        {
            const int curr = height[i];
            if (curr >= highest.first)
                highest = std::make_pair(curr, i);
            
            const int area = i * std::min(curr, first);
            if (area > largest)
                largest = area;
        }
        
        // Check numbers further than highest
        for (int i = 1; i < highest.second; ++i)
        {
            first = height[i];
            
            for (int j = std::max(highest.second, largest/highest.first + i); j < size; ++j)
            {
                const int area = (j - i) * std::min(first, height[j]);
                if (area > largest)
                    largest = area;
            }
        }
        
        // Check numbers from highest
        for (int i = std::max(highest.second + 1, largest/highest.first + 1); i < size; ++i)
        {
            const int area = (i - highest.second) * (height[i]);
            if (area > largest)
                largest = area;
        }
        
        return largest;
    }
};