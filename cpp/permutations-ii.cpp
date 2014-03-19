class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > output;
        if(num.size() == 0)
            return output;
            
        sort(num.begin(), num.end());
        output.push_back(num);
        while(next_permutation(num.begin(), num.end()))
        {
            output.push_back(num);
        }
        return output;
    }
};
