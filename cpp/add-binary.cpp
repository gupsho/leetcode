class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() == 0)
            return b;
        if(b.length() == 0)
            return a;
        
        int alength = a.length() - 1, blength = b.length() - 1;
        string out="";
        bool carry = false;
        while(alength >= 0 && blength >= 0) {
            if(a[alength] != b[blength]) {
                if(carry)
                    out = "0" + out;
                else
                    out = "1" + out;
            } else if (a[alength] == '1') {
                if(carry)
                    out = "1" + out;
                else 
                    out = "0" + out;
                carry = true;
            }
            else {
                if(carry) {
                    out = "1" + out;
                    carry = false;
                }
                else 
                    out = "0" + out;
            }
            alength--;
            blength--;
        }
        
        if(alength >= 0) {
            for(int i = alength; i >= 0; i--) {
                if(a[i] == '1') {
                    if(carry)
                        out = "0" + out;
                    else 
                        out = "1" + out;
                } else {
                    if(carry) {
                        carry = false;
                        out = "1" + out;
                    } else
                        out = "0" + out;
                }
            }
        }
        if(blength >= 0) {
            for(int i = blength; i >= 0; i--) {
                if(b[i] == '1') {
                    if(carry)
                        out = "0" + out;
                    else {
                        carry = false;
                        out = "1" + out;
                    }
                } else {
                    if(carry) {
                        carry = false;
                        out = "1" + out;
                    } else
                        out = "0" + out;
                }
            }
        }
        
        if(carry)
            out = "1" + out;
        return out;
    }
};
