class Solution {
public:
    int sqrt(int x) {
        /*int estimate = x/2;
        
        if(x == 1)
            return 1;
        
        while (estimate*estimate != x)
        {
            estimate = (x + x/estimate)/2;
        }
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        return estimate;*/
        int start = 0, end = x, mid = (start+end)/2;
        
        if(x == 0 || x == 1)
            return x;

        while(1)
        {
                if( mid == (x/mid))
                        return mid;
                else if(mid > (x/mid))
                {
                        end = mid;
                }
                else
                        start = mid;
                if(mid == (start + end)/2)
                        return mid;

                mid = (start + end)/2;

        }

        return mid;
    }
};
