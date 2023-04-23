// https://leetcode.com/problems/valid-palindrome/
// 125. Valid Palindrome

class Solution {
public:
    bool isPalindrome(string s) {
        int front = 0;
        int back = s.size() - 1;

        while (front <= back) {
            while(front <= back && !isalnum(s[front])) {
                front++;
            }

            while(front <= back && !isalnum(s[back])) {
                back--;
            }

            if (front <= back && tolower(s[front]) != tolower(s[back])) {
                return false;
            }

            front++;
            back--;
        }
        
        return true;
    }
};