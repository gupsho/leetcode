class Solution {
public:
    double pow(double x, int n) {
        if(x == 0 || x == 1)
            return x;
        if(n == 0)
            return 1;
            
        if(x < 0)
        {
            if(n%2 == 0)
                return pow(-1*x, n);
        }
            
        if(n < 0)
            return pow(1/x, -1*n);
        
        if(n % 2 == 0)
            return pow(x*x, n/2);
        else
            return x*pow(x*x, n/2);
        
    }
};
