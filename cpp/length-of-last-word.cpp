class Solution {
public:
    string reverse(const char *str)
    {
        string s;
        int len = strlen(str);
        for(int i = len - 1; i >= 0; i--)
        {
            s += str[i];
        }
        return s;
    }
    int lengthOfLastWord(const char *s) {
        if(strlen(s) == 0)
            return 0;
        string str = reverse(s);
        
        int index = 0;
        while(str[index] == ' ' || str[index] == '\t')
            index++;
        
        int count = 0;
        while(str[index] != ' ' && str[index] != '\t' && index != strlen(s))
        {
            count++;
            index++;
        }
        return count;
    }
};
