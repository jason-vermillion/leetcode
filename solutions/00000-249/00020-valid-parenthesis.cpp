class Solution {
public:
    bool isValid(string s) {
        bool ret = true;
        char c;
        stack<char> stack;
        
        for (int i = 0; i < s.size(); i++) {
            c = s[i];
            
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            }
            else if (c == ')' && !stack.empty() && stack.top() == '(') {
                stack.pop();
            }
            else if (c == ']' && !stack.empty() && stack.top() == '[') {
                stack.pop();
            }
            else if (c == '}' && !stack.empty() && stack.top() == '{') {
                stack.pop();
            }
            else {
                ret = false;
                break;
            }
        }
        
        if (stack.size() != 0) {
            ret = false;
        }
        
        return ret;
    }
};

