class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 2)
            return n;
        int count = 1, index = 1, size = 1;
        int num = A[0];
        for(int i = 1; i < n; i++)
        {
            if(A[i] == num && count < 2)
            {
                count++;
                size++;
            }
            else if(A[i] != num)
            {
                num = A[i];
                count = 1;
                size++;
            }
            
            A[size -1] = A[i];
        }
        return size;
    }
};
