class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longestPrefix = "";
        int maxLen = 0;
        int wordCount = 0;
        bool isSearching = true;
        char c;
        
        wordCount = strs.size();
        if (wordCount <= 0) {
            return longestPrefix;
        }
        
        for (int i = 0; i < wordCount; i++) {
            if (strs[i].length() > maxLen) {
                maxLen = strs[i].length();
            }
        }
        
        for (int i = 0; i < maxLen && isSearching; i++) {
            for (int j = 0; j < wordCount; j++) {
                if (i >= strs[j].length()) {
                    isSearching = false;
                    break;
                }
                else if (j == 0) {
                    c = strs[j].at(i);
                }
                else if (strs[j].at(i) != c) {
                    isSearching = false;
                    break;
                }
            }
            
            if (isSearching) {
                longestPrefix += c;
            }
        }
        
        
        return longestPrefix;
    }
};