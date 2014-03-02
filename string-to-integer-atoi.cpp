class Solution {
public:
    int atoi(const char *str) {
        int index = 0, sign = 1, num = 0;
        while(str[index] == '\n' || str[index] == ' ' || str[index] == '\t')
            index++;
        
        if(str[index] == '-')
        {
            index++;
            sign = -1;
        }
        else if(str[index] == '+')
        {
            index++;
            sign = 1;
        }
        
        int digit = str[index] - '0';
        while(digit >=0 && digit <=9)
        {
            if(sign == 1)
            {
                if(num > (INT_MAX - digit)/10)
                {
                    num = INT_MAX;
                    return num;
                }
            }
            else
            {
                if((-1*num) < (INT_MIN + digit)/10)
                {
                   num = INT_MIN;
                   return num;
                }
            }
            num = num*10 + digit;
            index++;
            digit = str[index] - '0';
        }
        return num*sign;
    }
};
