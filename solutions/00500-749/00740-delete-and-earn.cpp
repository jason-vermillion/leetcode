// https://leetcode.com/problems/delete-and-earn/
// 740. Delete and Earn
// dp, similar to house robber algorithm
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const int N = 10001;
        vector<int> freq(N, 0);
        vector<int> dp(N, 0);
        
        for (auto val : nums) {
            freq[val] += val;
        }
        
        dp[1] = freq[1];
        for (int i = 2; i < N; ++i) {
            dp[i] = max(freq[i] + dp[i - 2], dp[i-1]);
        }
        
        return dp[N - 1];
    }
    
    void printVector(vector<int>& nums, int start, int end) {
        cout << "[";
        for (int i = start; i <= end; ++i) {
            if (i > start) {
                cout << ",";
            }
            cout << nums[i];
            
        }
        cout << "]\n";
    }
};