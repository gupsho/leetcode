class Solution {
public:
    bool canJump(int A[], int n) {
        int i = 0;
        if(n <= 1)
            return true;
        while(i < (n - 1) && A[i] > 0)
            i = A[i] + i;
        if(i >= (n -1))
            return true;
        return false;
        
    }
};
