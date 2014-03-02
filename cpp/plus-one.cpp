class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int size = digits.size();
        int carry = 1;
        vector<int> plus;

        for(int i = size - 1; i >= 0; i--)
        {
                if(digits[i] == 9 && carry == 1)
                {
                        plus.insert(plus.begin(), 0);
                        carry = 1;
                }
                else if(carry == 1)
                {
                        plus.insert(plus.begin(), digits[i] + 1);
                        carry = 0;
                }
                else
                        plus.insert(plus.begin(), digits[i]);
        }
        if(carry)
            plus.insert(plus.begin(), 1);

        return plus;
    }
};
