// https://leetcode.com/problems/score-of-parentheses/
// 856. Score of Parentheses
class Solution {
public:
    int scoreOfParentheses(string s) {
        int total = 0;
        int n = s.size();
        stack<int> st;
        
        if (n == 0) return 0;
        
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == '(') {
                st.push(-1); // use -1 to designate "("
            }
            else { // found a ")"
                if (!st.empty() && st.top() == -1) {
                    st.pop();
                    st.push(1);
                }
                else {
                    int sum = 0;
                    while(!st.empty() && st.top() != -1) {
                        sum += st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(2 * sum);
                }
            }
        }
        
        total = 0;
        while (!st.empty()) {
            total += st.top();
            st.pop();
        }
        
        return total;
    }
};