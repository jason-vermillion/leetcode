// https://leetcode.com/problems/counting-bits/
// 338. Counting Bits
class Solution {
public:
    
    vector<int> countBits(int n) {
        vector<int> result(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            result[i] = result[i / 2];
            if (i & 1) {
                result[i]++;
            }
        }
        
        return result;
    }

    
    
    /** brute force - passes
    *
    vector<int> countBits(int n) {
        vector<int> result;
        
        for (int i = 0; i <= n; ++i) {
            int m = i;
            int cnt = 0;
            while (m > 0) {
                if (m & 1) {
                    cnt++;
                }
                m = m >> 1;
            }
            result.push_back(cnt);
        }
        
        return result;
    }
    */
};