// https://leetcode.com/problems/climbing-stairs/
// 70. Climbing Stairs
// Time Complexity O(N)
// Space Complexity O(1)
// DP

class Solution {
public:
    int climbStairs(int n) {
        int total = 0;
        int s2 = 1; // 2 steps behind
        int s1 = 2; // 1 step behind
        
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        for (int i = 3; i <= n; ++i) {
            total = s1 + s2;
            s2 = s1;
            s1 = total;
        }
        
        return total;
    }
};


/*
// Time Complexity O(N)
// Space Complexity O(N)
// DP

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        
        for (int i = 3; i <= n; ++i) {
            dp[i] += dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
};
*/