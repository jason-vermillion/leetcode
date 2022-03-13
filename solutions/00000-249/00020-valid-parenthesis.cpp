// https://leetcode.com/problems/valid-parentheses/
// 20. Valid Parentheses
class Solution {
public:
    bool isValid(string s) {
        bool result = false;
        stack<char> st;
        int n = s.length();
        
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            else if (c == ')' && !st.empty() && st.top() == '(') {
                st.pop();
            }
            else if (c == ']' && !st.empty() && st.top() == '[') {
                st.pop();
            }
            else if (c == '}' && !st.empty() && st.top() == '{') {
                st.pop();
            }
            else {
                st.push(c);
            }
        }
        
        return st.empty();
    }
};