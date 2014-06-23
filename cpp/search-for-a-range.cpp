class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> output;
        int mid = binarySearch(A, 0, n - 1, target);
        if(mid == -1)
        {
            output.push_back(mid);
            output.push_back(mid);
            return output;
        }
        int start = backSearch(A, 0, mid - 1, target);
        int end = forSearch(A, mid + 1, n -1, target);
        
        if(start > mid || start == -1) 
            start = mid;
        if(end < mid || end == -1)
            end = mid;
        output.push_back(start);
        output.push_back(end);
        return output;
    }
    
    int backSearch(int A[], int start, int end, int num) {
        if(start > end)
            return -1;
        int i = end;
        while(A[i] == num && i >= start)
            i--;
        return i+1;
    }

    int forSearch(int A[], int start, int end, int num) {
        if(start > end)
            return -1;
        int i = start;
        while(A[i] == num && i <= end)
            i++;
        return i -1;
    }
    
    int binarySearch(int A[], int start, int end, int num) {
        if(start > end)
            return -1;
        int mid = (start + end) /2;
        if(A[mid] == num)
            return mid;
        else if(A[mid] < num)
            return binarySearch(A, mid+1, end, num);
        else
            return binarySearch(A, start, mid -1, num);
    }
};
