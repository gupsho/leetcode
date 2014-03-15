class Solution {
public:
    int romanToInt(string s) {
        int number = 0;
        map<char, int> hash;
        hash['i'] = 1;
        hash['v'] = 5;
        hash['x'] = 10;
        hash['l'] = 50;
        hash['c'] = 100;
        hash['d'] = 500;
        hash['m'] = 1000;
        
        if(s.length() == 0)
            return number;
         
        int previous = 0, current = 0;   
        for(int i = 0; i < s.length(); i++)
        {
            current = hash[tolower(s[i])];
            if(previous < current)
                number += (current - previous - previous);
            else
                number += current;
            previous = current;
        }
        
        return number;
    }
};
