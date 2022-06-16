class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int height = matrix.size();
        const int width = matrix[0].size();
        
        int min = 0;
        int max = height * width;
        
        while (min < max)
        {
            const int mid = (min + max) / 2;
            const int num = matrix[mid / width][mid % width];
            
            if (num == target)
            {
                return true;
            }
            
            if (num < target)
            {
                if (min == mid)
                {
                    ++min;
                }
                else
                {
                    min = mid;
                }
            }
            else
            {
                max = mid;
            }
        }
        
        return false;
    }
};