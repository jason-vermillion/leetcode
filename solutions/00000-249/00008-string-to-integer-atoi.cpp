// https://leetcode.com/problems/string-to-integer-atoi/
// 8. String to Integer (atoi)
// Time complexity O(N)
class Solution {
public:
    int myAtoi(string s) {
        int value = 0;
        int sign = 1;
        int i = 0;
        int n = s.size();
        
        if (n == 0) return 0;
        
        // handle any leading space characters
        while (i < n) {
            if (s[i] != ' ') break;
            i++;
        }
        
        // handle optional sign char
        if (s[i] == '+') {
            i++;   
        }
        else if (s[i] == '-') {
            sign = -1;
            i++;
        }
        
        // handle digits
        while (i < n) {
            int d = s[i] - '0';
            if (d < 0 || d > 9) break; // non-numeric char
            
            // INT_MIN: -2147483648, INT_MAX: 2147483647
            if (value > INT_MAX / 10 || value == INT_MAX / 10 && d > 7) {
                return (sign > 0) ? INT_MAX : INT_MIN;
            }

            value = value * 10 + d;
            i++;
        }
        
        return sign * value;
        
    }
};