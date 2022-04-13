// https://leetcode.com/problems/baseball-game/
// 682. Baseball Game
// Time complexity O(N)
// Space complexity O(N)
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int total = 0;
        stack<int> st;
        int a, b;
        
        for (string op : ops) {
            if (op == "+") {
                b = st.top();
                st.pop();
                a = st.top();
                st.push(b);
                st.push(a + b);
            }
            else if (op == "D") {
                a = st.top();
                st.push(2 * a);
            }
            else if (op == "C") {
                st.pop();
            }
            else {
                a = stoi(op);
                st.push(a);
            }
        }
        
        while(!st.empty()) {
            total += st.top();
            st.pop();
        }
        
        return total;
    }
};