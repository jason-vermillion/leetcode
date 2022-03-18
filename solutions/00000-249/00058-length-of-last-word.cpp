// https://leetcode.com/problems/length-of-last-word/
// 58. Length of Last Word
// Time complexity O(n)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int n = s.size();
        int wordEnd;
        
        // find the end of the last word in the string.
        wordEnd = n - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] != ' ') break;
            wordEnd--;
        }
        
        // find the length of the last word.
        for (int i = wordEnd; i >= 0; --i) {
            if (s[i] == ' ') break;
            len++;
        }
        
        return len;
    }
};