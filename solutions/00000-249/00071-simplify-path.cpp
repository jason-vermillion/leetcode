// https://leetcode.com/problems/simplify-path/
// 71. Simplify Path
class Solution {
public:
    string simplifyPath(string path) {
        string result = "";
        int n = path.size();
        vector<string> pathParts;
        
        for (int i = 0; i < n; ++i) {
            if (path[i] == '/') continue;
            
            string token = "";
            while (i < n) {
                if (path[i] == '/') {
                    break;
                }
                token += path[i];
                i++;
            }
            
            if (token == ".." && pathParts.size() > 0) {
                pathParts.pop_back();
            }
            else if (token != "." && token != ".." && token.size() > 0) {
                pathParts.push_back(token);
            }
        }

        for (int j = 0; j < pathParts.size(); j++) {
            result += "/" + pathParts[j];
        }
        
        if (result.size() == 0) {
            result = "/";
        }
        
        return result;
    }
};