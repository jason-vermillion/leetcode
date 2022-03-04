// https://leetcode.com/problems/longest-palindromic-substring/
// 5. Longest Palindromic Substring

// using dp O(n^2) dynamic programming
class Solution {
public:
    string longestPalindrome(string s) {
        string result = "";
        int n = s.size();
        int maxLen = INT_MIN;
        int longestStart = 0;
        int longestLen = 0;
        vector<vector<bool>> dp(n, vector(n, false)); // 2-dimensional array for dp[start][end] is a palindrome.
        int start, end;
        
        if (n <= 1) return s;
        
        for (start = 0; start < n; ++start) {
            dp[start][start] = true; // single character strings are palindromes.
        }
        
        longestStart = 0;
        longestLen = 1;
        
        for (end = 0; end < n; ++end) {
            for (start = end - 1; start >= 0; --start) {
                int len = end - start + 1;
                if (len == 1 || (s[start] == s[end] && (len == 2 || dp[start + 1][end - 1]))) {
                    dp[start][end] = true;
                    if (len > maxLen) {
                        maxLen = len;
                        longestStart = start;
                        longestLen = len;
                    }
                }        
            }
        }
        
        result = s.substr(longestStart, longestLen);
        
        return result;
    }
};

/*
// brute force, passes but slow O(n^3)
class Solution {
private:
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        string result = "";
        int maxLen = 0;
        int len = 1;
        int n = s.size();
        
        if (n == 1) return s;
        
        for (len = 1; len <= n; len++) {
            for (int i = 0; i <= n - len; ++i) {
                if (isPalindrome(s, i, i + len -1) && len > maxLen) {
                    maxLen = len;
                    result = s.substr(i, len);
                }
            }
        }
        
        return result;
    }
};
*/