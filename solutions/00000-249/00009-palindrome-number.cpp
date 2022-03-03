// https://leetcode.com/problems/palindrome-number/
class Solution {
public:
    bool isPalindrome(int x) {
        int t = x;
        int reversed = 0;
        
        if (x < 0) return false;
        
        while(t > 0) {
            if (INT_MAX / 10 < reversed) {
                return false;
            }
            reversed = reversed * 10 + t % 10;
            t = t / 10;
        }
        
        return (x == reversed);
    }
};