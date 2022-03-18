// https://leetcode.com/problems/remove-duplicate-letters/
// 316. Remove Duplicate Letters
// Time complexity O(N)
// stack
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> lastCharIndex(26, 0); // last postion of a char in the input string.
        vector<bool> inString(26, false); // if the character is already in the output string.
        stack<int> st;
        string result = "";
        
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            lastCharIndex[c] = i;
        }
        
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            
            if (inString[c]) continue;
            
            while (st.size() > 0 && st.top() > c && i < lastCharIndex[st.top()]) {
                int p = st.top();
                inString[p] = false;
                st.pop();
            }
            st.push(c);
            inString[c] = true;
        }
        
        while(!st.empty()) {
            char c = st.top() + 'a';
            result = c + result;
            st.pop();
        }
        
        return result;
    }
};