class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int count = 0;
        if(n > 0)
            count++;
        for(int i = 1; i < n; i++)
        {
            if(A[i] != A[i-1])
                count++;
            A[count - 1] = A[i];
        }
        return count;
    }
};
