// https://leetcode.com/problems/valid-palindrome-ii/
// 680. Valid Palindrome II
// Time complexity O(N)
// space complexity O(1)
// brute force method is O(n2) and fails with TLE
class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        
        while (left < right) {
            if (s[left] != s[right]) {
                return (inner(s, left + 1, right) || inner(s, left, right - 1));
            }
            left++;
            right--;
        }
        
        return true;
    }
    
private:
    bool inner(string s, int left, int right) {
        
        while(left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};