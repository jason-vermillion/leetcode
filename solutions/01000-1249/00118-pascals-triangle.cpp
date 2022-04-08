// https://leetcode.com/problems/pascals-triangle/
// 118. Pascal's Triangle
// Time complexity O(N^2)
// Space complexity O(N^2)
// DP, pascal
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> result;
        
        for (int i = 0; i < n; ++i) {
            // first and last element in each row is 1
            vector<int> r = vector<int>(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                r[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(r);
        }
        
        return result;
        
    }
};