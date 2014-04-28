class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int num = x, count = 0;
        while(num > 0)
        {
            num /= 10;
            count ++;
        }
        
        int i = 1, XOR = 0;
        while(x > 0)
        {
            if(i != ((count+1)/2) || count %2 == 0)
                XOR ^= (x%10);
            x /= 10;
            i++;
        }
        return XOR == 0;
    }
};
