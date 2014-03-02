class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int i = m - 1, j = n - 1, k = m + n - 1;
        while(i >= 0 && j >= 0)
        {
            if(A[i] < B[j]) {
                A[k--] = B[j--];
            }
            else {
                A[k--] = A[i--];
            }
        }
        while(i >= 0) {
                A[k--] = A[i--];
        }
        
        while(j >= 0) {
            A[k--] = B[j--];
        }
        
    }
};
