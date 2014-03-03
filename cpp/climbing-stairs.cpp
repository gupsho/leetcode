class Solution {
public:
    int climbStairs(int n) {
        return fibonacci(n + 1);
    }
private: 
    int fibonacci(int n) {
        int a = 0;
        int b = 1;
        while (n-- > 1) {
            int t = a;
            a = b;
            b += t;
        }
    return b;
    }
};
