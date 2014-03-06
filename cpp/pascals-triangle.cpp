class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > triangle;
        if(numRows == 0)
            return triangle;
        
        vector<int> first;
        
        first.push_back(1);
        
        triangle.push_back(first);
        
        if(numRows == 1)
            return triangle;
            
        for(int i = 1; i < numRows; i ++ )
        {
            vector<int> row;
            row.push_back(triangle[i-1][0]);
            for(int j = 1; j < triangle[i-1].size(); j ++)
            {
                row.push_back(triangle[i-1][j-1] + triangle[i-1][j]);
            }
            row.push_back(triangle[i-1][0]);
            triangle.push_back(row);
        }
        
        return triangle;
        
    }
};
