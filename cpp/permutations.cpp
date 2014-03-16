class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > result;
        permutations(result, num, 0, num.size() - 1);
        return result;
    }
    
    void permutations(vector<vector<int> > &result, vector<int> &num, int start, int end)
    {
        if(start == end)
            result.push_back(num);
            
        for(int i = start; i <= end; i ++)
        {
            int temp = num[start];
            num[start] = num[i];
            num[i] = temp;
            permutations(result, num, start + 1, end);
            temp = num[start];
            num[start] = num[i];
            num[i] = temp;
        }
    }
};
