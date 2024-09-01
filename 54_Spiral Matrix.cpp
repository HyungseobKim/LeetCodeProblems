class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const int NumRows = matrix.size();
        const int NumColumns = matrix[0].size();
        std::vector<int> OutBuffer(NumRows*NumColumns);

        int x = -1, y = 0; // Indicates the index for matrix.
        int sign = 1; // Increment modifier.
        int index = 0; // Index for OutBuffer.

        // Until one of width or height becomes 0.
        for (int width = NumColumns, height = NumRows; width > 0 && height > 0; --width, --height)
        {
            // How many bits should be pushed.
            const int push = width + height;
            
            // Set variables.
            const int test = 1 << push;
            int col = test + (test - width);
            int row = test - width;

            // Loop for 2 edges (1 horizontally, 1 vertically).
            const int end = col + width + height - 1;
            while (col < end)
            {
                // Find the index.
                x += sign * ((col & test) >> push);
                y += sign * ((row & test) >> push);

                OutBuffer[index] = matrix[y][x];
                ++index;

                // Go to the next element.
                ++col;
                ++row;
            }

            // Reverse the sign.
            sign *= -1;
        }

        return OutBuffer;
    }
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int right = matrix[0].size() - 1;
        int bottom = matrix.size() - 1;
        int left = 0;

        std::vector<int> result(matrix.size() * matrix[0].size());
        int index = 0;

        while (top <= bottom && left <= right)
        {
            for (int col = left; col <= right; ++col)
            {
                result[index++] = matrix[top][col];
            }
            ++top;

            for (int row = top; row <= bottom; ++row)
            {
                result[index++] = matrix[row][right];
            }
            --right;

            if (top <= bottom)
            {
                for (int col = right; col >= left; --col)
                {
                    result[index++] = matrix[bottom][col];
                }
                --bottom;
            }
            
            if (left <= right)
            {
                for (int row = bottom; row >= top; --row)
                {
                    result[index++] = matrix[row][left];
                }
                ++left;
            }
        }

        return result;
    }
};