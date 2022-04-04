// https://leetcode.com/problems/counting-bits/
// 338. Counting Bits
// Time complexity O(N)
// Space complexity O(N)
class Solution {
public:
    
    vector<int> countBits(int n) {
        vector<int> result(n + 1);
        
        result[0] = 0;
        for (int i = 1; i <= n; ++i) {
            // result[i] = result[i / 2] + (i & 1);
            result[i] = result[i / 2] + (i % 2);
        }
        
        return result;
    }
};