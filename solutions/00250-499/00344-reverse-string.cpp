// https://leetcode.com/problems/reverse-string/
// 344. Reverse String
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        char swap;
        
        while (left < right) {
            swap = s[left];
            s[left] = s[right];
            s[right] = swap;
            
            left++;
            right--;
        }
    }
};