class Solution {
public:
    void sortColors(int A[], int n) {
        if(n == 0 || n == 1)
            return;
        int start = 0, end = n - 1, i = 0;
        while(i<=end)
        {
                if (A[i] < 1)
                {
                        int num = A[i];
                        A[i++] = A[start];
                        A[start++] = num;
                }
                else if(A[i] > 1)
                {
                        int num = A[i];
                        A[i] = A[end];
                        A[end--] = num;
                }
                else
                        i++;
        }

        for(int i = start; i < end; i ++)
                A[i] = 1;
        
    }
};
