// https://leetcode.com/problems/plus-one/
// 66. Plus One
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        
        if (n == 0) return digits;
        
        for (int i = n - 1; i >= 0; --i) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        
        digits[0] = 1;
        digits.push_back(0);
        
        return digits;
    }
};

// https://leetcode.com/problems/plus-one/
// 66. Plus One
// brute force method passes O(n)
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int n = digits.size();
        
        // reverse the digits
        for (int i = n - 1; i >= 0; --i) {
            result.push_back(digits[i]);
        }
        
        // Add 1
        int carry = 1;
        for (int i = 0; i < n; ++i) {
            int v = result[i] + carry;
            result[i] = v % 10;
            carry = v / 10;
        }
        
        if (carry > 0) {
            result.push_back(carry);
        }
        
        reverse(result.begin(), result.end());
        
        return result;
    }
};