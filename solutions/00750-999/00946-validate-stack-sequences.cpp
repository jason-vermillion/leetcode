// https://leetcode.com/problems/validate-stack-sequences/
// 946. Validate Stack Sequences
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        
        for (int i = 0, j = 0; i < n; ++i) {
            st.push(pushed[i]);
            //printf("i: %d, pushed: %d\n", i, pushed[i]);
            
            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                //printf("j: %d, popped: %d\n", j, popped[j]);
                j++;
            }
        }
        
        return st.empty();
    }
};