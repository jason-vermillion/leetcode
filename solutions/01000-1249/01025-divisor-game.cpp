// https://leetcode.com/problems/divisor-game/
// 1025. Divisor Game
// TODO: revisit
class Solution {
public:
    bool divisorGame(int n) {
        return n % 2 == 0;
    }    
};

/*
// dp method tle
class Solution {
public:
    bool divisorGame(int n) {
        vector<int> dp(n + 1, 0); // 0 unvisited, -1 false, and 1 true
        return helper(dp, n);

    }
    
    bool helper(vector<int>& dp, int n) {
        if (dp[n] == 0) {
            for (int i = 1; dp[n] != 1 && i < n / 2; ++i) {
                if (n % i == 0 && !divisorGame(n - i)) {
                    dp[n] = 1;
                }
                else {
                    dp[n] = -1;
                }
            }
        }        
        
        return dp[n] == 1;
        
    }
};

*/


/*
// brute force method TLE
class Solution {
public:
    bool divisorGame(int n) {
        
        for (int i = 1; i < n; ++i) {
            if (n % i == 0 && !divisorGame(n - i)) {
                return true;
            }
        }
        return false;

    }
};
*/