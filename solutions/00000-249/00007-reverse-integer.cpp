// https://leetcode.com/problems/reverse-integer/
class Solution {
public:
    int reverse(int x) {
        int digit = 0;
        int val = 0;
        int rem = x;
        
        if (x == INT_MAX || x == INT_MIN) {
            return 0;
        }
        
        while (rem != 0) {
            digit = rem % 10;
            if (val > INT_MAX / 10 || val < INT_MIN / 10) {
                return 0;
            }
            val = 10 * val + digit;
            rem = rem / 10;
        }
        
        return val;
    }
};


// https://leetcode.com/problems/reverse-integer/
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        vector<int> digits;
        int isNegative = (x < 0);
        int y = x;
        
        if (x >= 2147483647 || x <= -2147483648) {
            return 0;
        }
        
        if (isNegative) {
            y = y * -1;
        }
        
        while (y > 0) {
            int r = y % 10;
            digits.push_back(r);
            y = y / 10;
        }
        
        
        // max int 2,147,483,647
        int p = 0;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (p > 0) {
                p = p * 10;
            }
            else {
                p = 1;
            }
            
            if (p > 1000000000) {
                // overflow
                return 0;
            }
            else if (p == 1000000000) {
                if (digits[i] > 2 || (digits[i] == 2 && res > 147483647)) {
                    // overflow
                    return 0;
                }
            }
            
            res += digits[i] * p;
        }
        
        if (isNegative) {
            res = res * -1;
        }
        
        return res;
    }
};