class Solution {
public:
    int maxSubArray(int A[], int n) {
        int maxSum = A[0], sum = A[0];
        
        for(int i = 1; i < n; i++)
        {
            if(sum < 0 )
                sum = A[i];
            else
                sum += A[i];
                
            if(sum > maxSum)
                maxSum = sum;
        }
        
        return maxSum;
        
    }
};
