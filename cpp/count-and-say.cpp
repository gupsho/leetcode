class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string current = "1";
        int count = 0;
        for(int i  = 1; i < n; i++)
        {
            char c = current[0];
            count = 1;
            string newString ="";
            for(int j = 1; j < current.length(); j++)
            {
                if(current[j] == c)
                    count++;
                else
                {
                    newString += (count + '0');
                    newString += c;
                    c= current[j];
                    count = 1;
                }
                
            }
            newString += (count + '0');
            newString += c;
            current = newString;
        }
        return current;
        
    }
};
