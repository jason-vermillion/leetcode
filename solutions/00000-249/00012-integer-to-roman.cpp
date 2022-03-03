class Solution {
public:
    string intToRoman(int num) {
        string  symbols[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int     values[] =  {1,    4,    5,   9,    10,  40,   50,  90,   100, 400,  500, 900,  1000};
        string result = "";
        int temp = num;
        int i = 0;
        
        i = 13 - 1;
        while (i >= 0) {
            if (temp >= values[i]) {
                result += symbols[i];
                temp = temp - values[i];
            }
            
            if (values[i] > temp) {
                i--;    
            }
            
        }
        return result;
        
    }
};