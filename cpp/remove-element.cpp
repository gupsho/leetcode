class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int count = 0;
        for(int i = 0; i<n; i++)
        {
            if(A[i] == elem)
                count ++;
            else
            {
                int num = A[i];
                A[i] = A[i - count];
                A[i - count] = num;
            }
        }
        
        return n - count;
    }
};
