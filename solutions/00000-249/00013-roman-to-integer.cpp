class Solution {
public:
    int romanToInt(string s) {
        int i = 0;
        int result = 0;
        int max = s.length();
        char numerals[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        int values[7] = {1, 5, 10, 50, 100, 500, 1000};
        
        while (i < max) {
            // handle IV, IX, XL, XC, etc.
            if (i < max - 1) {
                if (s[i] == 'I' && s[i+1] == 'V') {
                    result += 4;
                    i = i + 2;
                    continue;
                }
                else if(s[i] == 'I' && s[i+1] == 'X') {
                    result += 9;
                    i = i + 2;
                    continue;
                }
                else if(s[i] == 'X' && s[i+1] == 'L') {
                    result += 40;
                    i = i + 2;
                    continue;
                }
                else if(s[i] == 'X' && s[i+1] == 'C') {
                    result += 90;
                    i = i + 2;
                    continue;
                }
                else if(s[i] == 'C' && s[i+1] == 'D') {
                    result += 400;
                    i = i + 2;
                    continue;
                }
                else if(s[i] == 'C' && s[i+1] == 'M') {
                    result += 900;
                    i = i + 2;
                    continue;
                }
            }
            
            for (int j = 0; j < 7; j++) {
                if (s[i] == numerals[j]) {
                    result += values[j];
                }
            }
            
            i++;
        }
        
        return result;
        
    }
};