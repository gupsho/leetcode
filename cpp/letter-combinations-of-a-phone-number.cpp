class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> output;
        if(digits.size() == 0)
        {
            output.push_back("");
            return output;
        }
        
        generateAllPerms(digits, digits, 0, digits.size(), output);
        return output;
    }
    
    void generateAllPerms(string digits, string str, int start, int end, vector<string>& output) {
        const string keypad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if(start == end)
        {
            output.push_back(str);
            return;
        }
            
        int digit = digits[start] - '0';
        for(int i = 0; i < keypad[digit].size(); i++)
        {
            str[start] = keypad[digit][i];
            generateAllPerms(digits, str, start+1, end, output);
        }
        
    }
};
