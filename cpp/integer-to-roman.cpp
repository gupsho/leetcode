class Solution {
public:
    string intToRoman(int num) {
        string roman = "";
        map<int, string> hash;
        hash[1] = "I";
        hash[4] = "IV";
        hash[5] = "V";
        hash[9] = "IX";
        hash[10] = "X";
        hash[40] = "XL";
        hash[50] = "L";
        hash[90] = "XC";
        hash[100] = "C";
        hash[400] = "CD";
        hash[500] = "D";
        hash[900] = "CM";
        hash[1000] = "M";

        if(num <= 0)
            return roman;

        while(num)
        {
                while(num >= 1000)
                {
                        roman += hash[1000];
                        num -= 1000;
                }
                if(num>= 900)
                {
                        roman += hash[900];
                        num -= 900;
                }
                if(num >= 500)
                {
                        roman += hash[500];
                        num -= 500;
                }
                if(num >= 400)
                {
                        roman += hash[400];
                        num -= 400;
                }
                while(num >= 100)
                {
                        roman += hash[100];
                        num -= 100;
                }
                if(num >=90)
                {
                        roman += hash[90];
                        num -= 90;
                }
                if(num >= 50)
                {
                        roman += hash[50];
                        num -= 50;
                }
                if(num >=40)
                {
                        roman += hash[40];
                        num -= 40;
                }
                while(num >= 10)
                {
                        roman += hash[10];
                        num -= 10;
                }
                if(num >= 9)
                {
                        roman += hash[9];
                        num -= 9;
                }
                if(num >= 5)
                {
                        roman += hash[5];
                        num -= 5;
                }
                if(num >= 4)
                {
                        roman += hash[4];
                        num -= 4;
                }
                while(num >= 1)
                {
                        roman += hash[1];
                        num --;
                }
        }

        return roman;
    }
};
