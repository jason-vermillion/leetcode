// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
// 1249. Minimum Remove to Make Valid Parentheses
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        unordered_set<int> skipChars;
        int n = s.size();
        string result = "";
        
        // use stack to find all the unmatched parenthesis.
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            
            if (isalpha(c)) continue;
            
            if (c == '(') {
                st.push(i);
            }
            else if (c == ')' && !st.empty() && s[st.top()] == '(') {
                // found a matching pair of ().
                st.pop();
            }
            else {
                st.push(i);
            }
        }
        
        while(!st.empty()) {
            skipChars.insert(st.top());
            st.pop();
        }
        
        for (int i = 0; i < n; ++i) {
            if (skipChars.count(i) == 0) {
                result += s[i];
            }
        }
        
        return result;
    }
};