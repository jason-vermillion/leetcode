// https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
// 1663. Smallest String With A Given Numeric Value
// Time complexity O(N)
class Solution {
public:
    string getSmallestString(int n, int k) {
        string result(n, 'a');
        k = k - n;
        
        for (int i = n - 1; i >= 0; --i) {
            if (k == 0) break;
            
            int x = min(k, 25);
            k = k - x;
            result[i] = result[i] + x;
        }
        
        return result;
    }
};