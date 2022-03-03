// https://leetcode.com/problems/reverse-string/
class Solution {
public:
    void reverseString(vector<char>& s) {
        char swap = NULL;
        int m = s.size()/2;
        int i = 0;
        int j = s.size() - 1;
        while (i < m) {
            swap = s[i];
            s[i] = s[j];
            s[j] = swap;
            
            ++i;
            --j;
        }
    }
};