class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        
        if ((upper + lower) != std::accumulate(colsum.begin(), colsum.end(), 0))
            return vector<vector<int>>();
        
        const int length = colsum.size();
        
        vector<vector<int>> matrix(2, vector<int>(length));
        
        for (int i = 0; i < length; i++)
        {
            int col = colsum[i];
            
            if (col == 2)
            {
                matrix[0][i] = 1;
                matrix[1][i] = 1;
                
                --upper;
                --lower;
            }
            else if (col == 0)
            {
                matrix[0][i] = 0;
                matrix[1][i] = 0;
            }
        }
        
        if (upper < 0 || lower < 0) return vector<vector<int>>();
        
        for (int i = 0; i < length; i++)
        {
            if (colsum[i] != 1) continue;
            
            if (upper)
            {
                matrix[0][i] = 1;
                matrix[1][i] = 0;
                --upper;
            }
            else
            {
                matrix[0][i] = 0;
                matrix[1][i] = 1;
                --lower;
            }
        }
        
        if (upper || lower) return vector<vector<int>>();
        
        return matrix;
    }
};