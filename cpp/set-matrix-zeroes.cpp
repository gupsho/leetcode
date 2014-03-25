class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> rows;
        vector<int> cols;
        for(int i = 0; i < row; i++)
            rows.push_back(0);
        
        for(int i = 0; i < col; i++)
            cols.push_back(0);
        
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    rows[i] = 1;
                    cols[j] = 1;
                }
            }
        }
        
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[i].size(); j++)
            {
                if(rows[i] == 1 || cols[j] == 1)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
