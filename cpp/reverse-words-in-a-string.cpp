class Solution {
public:
    void reverseWords(string &s) {
        s = sanitiseString(s);
        removeLeadingSpaces(s);
        removeTrailingSpaces(s);
        reverseString(s, 0, s.length());
        int wordStart = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ')
            {
                reverseString(s, wordStart, i);
                wordStart = i+1;
            }
        }
        reverseString(s, wordStart, s.length());
    }
    
    void reverseString(string &s, int start, int end) {
        for(int i = 0; i < (end-start)/2; i++) {
        char c = s[start + i];
        s[start + i] = s[end - i - 1];
        s[end - i - 1] = c;
        }
    }

    
    string sanitiseString(string s) {
        string str;
        bool wordStart = true;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ' ')
            {
                if(!wordStart)
                    wordStart = true;
                str += s[i];
            }
            else
            {
                if(wordStart)
                {
                    wordStart = false;
                    str += s[i];
                }
            }
        }
        return str;
    }

    
    void removeTrailingSpaces(string &s)
    {
        while(s[s.length() - 1] == ' ')
            s = s.substr(0, s.length()-1);
    }
    
    void removeLeadingSpaces(string &s)
    {
        while(s[0] == ' ')
            s.erase(s.begin());
    }
};
