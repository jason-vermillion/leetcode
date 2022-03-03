// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// 3. Longest Substring Without Repeating Characters
// Time complexity O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charPosition; // index of the last occurence of a character.
        int n = s.size();
        int maxLen = 0;
        int len = 0;
        int seqStart = 0;
        
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            int x = -1;
            
            if (charPosition.count(c) != 0 && charPosition[c] >= seqStart) {
                x = charPosition[c];
                len = i - x;
                seqStart = x + 1;
            }
            else {
                len++;
            }
            
            charPosition[c] = i;
            
            maxLen = max(maxLen, len);
        }
        
        return maxLen;
    }
};