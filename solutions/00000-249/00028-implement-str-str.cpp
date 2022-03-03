// https://leetcode.com/problems/implement-strstr/
// 28. Implement strStr()
class Solution {
public:
    int strStr(string haystack, string needle) {
        int position;
        
        position = haystack.find(needle, 0);
        
        return position;
    }
};