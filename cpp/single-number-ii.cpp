class Solution {
public:
    int singleNumber(int A[], int n) {
        int num = 0;
        
        int temp = 0;
        for(int i = 0; i < 32; i++)
        {
            for(int j = 0; j < n; j ++)
            {
                if((A[j] >> i) & 1)
                    temp ++;
            }
            temp = temp %3;
            num = num | (temp<<i);
            temp = 0;
        }
        
        return num;
    }
};
