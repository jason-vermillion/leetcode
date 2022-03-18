// https://leetcode.com/problems/add-binary/
// 67. Add Binary
class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int lenA = a.size();
        int lenB = b.size();
        
        int carry = 0;
        for (int i = lenA - 1, j = lenB - 1; i >= 0 || j >= 0; --i, --j) {
            int vA = (i >= 0) ? a[i] - '0' : 0;
            int vB = (j >= 0) ? b[j] - '0' : 0;
            
            int sum = vA + vB + carry;
            
            char d = sum % 2 + '0';
            carry = sum / 2;
            result = d + result;
        }
        
        if (carry == 1) {
            result = '1' + result;
        }
        
        return result;
    }
};