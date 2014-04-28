class Solution {
public:
    int search(int A[], int n, int target) {
        int p = pivot(A, 0, n -1);
        if(p >= 0) {
            int left = binSearch(A, 0, p -1, target);
            int right = binSearch(A, p, n -1, target);
            if(left == right)
                return left;
            return left == -1 ? right:left;
        }
        else
            return binSearch(A, 0, n - 1, target);
    }
    
    int binSearch(int A[], int start, int end, int target) {
        if(end < start)
            return -1;
        int mid = (start + end)/2;
        if(A[mid] == target)
            return mid;
        else if(A[mid] > target)
            return binSearch(A, start, mid -1, target);
        else
            return binSearch(A, mid+1, end, target);
    }
    
    int pivot(int A[], int start, int end) {
        if(start > end)
            return -1;
        if(start == end)
            return start;
        int mid = (start + end)/2;
        if(A[mid] > A[end])
            return pivot(A, mid+1, end);
        else
            return pivot(A, start, mid);
    }
};
