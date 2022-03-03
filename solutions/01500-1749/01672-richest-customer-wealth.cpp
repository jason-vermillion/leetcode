// https://leetcode.com/problems/richest-customer-wealth/
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max = 0;
        int curr = 0;
        int cSize = accounts.size();
        for (int i = 0; i < cSize; ++i) {
            curr = 0;
            int aSize = accounts[i].size();
            for (int j = 0; j < aSize; ++j) {
                curr += accounts[i][j];
            }
            if (curr > max) {
                max = curr;
            }
        }
        return max;
    }
};