class Solution {
public:
    int reverse(int x) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int num = x, result = 0;
        if(x < 0)
            num *= -1;
        while(num) {
            result = result*10 + num%10;
            num /= 10;
        }
        if(x < 0)
            result *= -1;
            
        return result;
    }
};
