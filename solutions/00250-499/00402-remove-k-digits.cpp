// https://leetcode.com/problems/remove-k-digits/
// 402. Remove K Digits
// time complexity O(n)
class Solution {
public:
    string removeKdigits(string num, int k) {
        int sz = num.size();
        string output = "";
        stack<char> s;
        int remainingDeletes = k;
        
        if (k >= sz) {
            return "0";
        }
        
        for (int i = 0; i < sz; ++i) {
            char c = num[i];
            while(!s.empty() && remainingDeletes > 0 && c < s.top()) {
                s.pop();
                remainingDeletes--;
            }
            
            if (!s.empty() || c != '0') {
                s.push(c);   
            }
        }
        
        // use up any extra deletes left over
        while (!s.empty() && remainingDeletes > 0) {
            s.pop();
            remainingDeletes--;
        }
        
        // build the output
        while (!s.empty()) {
            output = s.top() + output;
            s.pop();                
        }
        
        if (output.length() == 0) {
            output = "0";
        }
        
        return output;
    }
};