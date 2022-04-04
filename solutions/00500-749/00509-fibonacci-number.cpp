// https://leetcode.com/problems/fibonacci-number/
// 509. Fibonacci Number
// Time complexity O(N)
class Solution {
public:
    int fib(int n) {
        int dpLen = max(2, n + 1);
        vector<int> dp(dpLen, 0);
        
        dp[0] = 0;
        dp[1] = 1;
        
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
};