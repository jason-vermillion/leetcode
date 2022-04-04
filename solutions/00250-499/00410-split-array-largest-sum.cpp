// https://leetcode.com/problems/split-array-largest-sum/
// 410. Split Array Largest Sum
// DP
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        
        dp[0][0] = nums[0];
        
        for (int i = 1; i < n; ++i) {
            dp[0][i] = dp[0][i - 1] + nums[i];
        }
        
        for (int i = 1; i < m; ++i) {
            for (int j = i; j < n; ++j) {
                int minS = INT_MAX;
                for (int x = 0; x < j; ++x) {
                    minS = min(minS, max(dp[i - 1][x], dp[0][j] - dp[0][x]));
                }
                dp[i][j] = minS;
            }
        }
        return dp[m - 1][n - 1];
    }
};