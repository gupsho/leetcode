class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int arr[n + 1];
        for(int i = 0; i <= n; i++)
            arr[i] = 0;
            
        for(int i = 0; i < n; i++)
        {
            if(A[i] > 0 && A[i] <= n)
                arr[A[i]] = 1;
        }
        for(int i = 1; i <= n; i++)
        {
            if(arr[i] == 0)
                return i;
        }
        return n+1;
        
    }
};
