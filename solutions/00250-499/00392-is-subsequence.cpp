// https://leetcode.com/problems/is-subsequence/
// 392. Is Subsequence
class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool result = false;
        int p2 = 0;
        char c;
        int n1 = s.size();
        int n2 = t.size();
        
        if (s.size() > t.size()) return false;
        if (s.size() == 0) return true;
        
        for (int i = 0; i < n1; ++i) {
            char c1 = s[i];
            result = false;
            while (p2 < n2) {
                char c2 = t[p2];
                p2++;
                if (c2 == c1) {
                    result = true;
                    break;
                }
            }
        }
        
        return result;
    }
};