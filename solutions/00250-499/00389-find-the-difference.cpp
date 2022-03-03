// https://leetcode.com/problems/find-the-difference/
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> freqS(26, 0);
        vector<int> freqT(26, 0);
        char res;
        
        for (auto c : s) {
            freqS[c - 'a']++;
        }
        
        for (auto c : t) {
            freqT[c - 'a']++;
        }
        
        for (int i = 0; i < 26; ++i) {
            if (freqS[i] != freqT[i]) {
                res = 'a' + i;
                break;
            }
        }
        
        return res;
    }
};