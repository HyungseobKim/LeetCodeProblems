/*
	Solution 1
	Uses O(width) extra space at most, but takes lesser time.
	
	Solution 2
	Uses a constant extra space, so takes lesser memories but takes little more time.
	
	Time complexity is the same.
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int height = matrix.size();
        const int width = matrix[0].size();

        std::set<int> columnsToBeZero;

        for (std::vector<int>& row : matrix)
        {
            bool setThisColumnZero = false;

            for (int col = 0; col < width; ++col)
            {
                if (row[col] == 0)
                {
                    columnsToBeZero.insert(col);
                    setThisColumnZero = true;
                }
            }

            if (setThisColumnZero)
            {
                for (int col = 0; col < width; ++col)
                {
                    row[col] = 0;
                }
            }
        }

        for (std::vector<int>& row : matrix)
        {
            for (int col : columnsToBeZero)
            {
                row[col] = 0;
            }
        }
    }
};

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int height = matrix.size();
        const int width = matrix[0].size();

        bool setFirstColumnZero = false;

        if (matrix[0][0] == 0)
        {
            setFirstColumnZero = true;
        }

        // Initialize the first row
        for (int col = 1; col < width; ++col)
        {
            if (matrix[0][col] == 0)
            {
                matrix[0][0] = 0;
            }
        }

        // Initialize the first column        
        for (int row = 1; row < height; ++row)
        {
            if (matrix[row][0] == 0)
            {
                setFirstColumnZero = true;
            }
        }

        // Find all zeroes
        std::vector<int>& firstRow = matrix[0];
        for (int i = 1; i < height; ++i)
        {
            std::vector<int>& row = matrix[i];

            for (int col = 1; col < width; ++col)
            {
                if (row[col] == 0)
                {
                    row[0] = 0;
                    firstRow[col] = 0;
                }
            }
        }

        // Set zeroes for all the columns except the first one
        for (int i = 1; i < height; ++i)
        {
            std::vector<int>& row = matrix[i];

            for (int col = 1; col < width; ++col)
            {
                if (firstRow[col] == 0)
                {
                    row[col] = 0;
                }
            }
        }

        // Set zeroes for all the rows
        for (std::vector<int>& row : matrix)
        {
            if (row[0] == 0)
            {
                for (int col = 1; col < width; ++col)
                {
                    row[col] = 0;
                }
            }
        }

        // Set the first column zero
        if (setFirstColumnZero)
        {
            for (std::vector<int>& row : matrix)
            {
                row[0] = 0;
            }
        }
    }
};