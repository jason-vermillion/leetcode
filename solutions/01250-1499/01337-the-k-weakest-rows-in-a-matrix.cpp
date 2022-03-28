// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
// 1337. The K Weakest Rows in a Matrix
// Time complexity O(NLogN)
// space complexity O(N)
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> orderedRows; // strength to index map
        vector<int> result(k, -1);
        
        int cols = mat[0].size();
        for (int row = 0, n = mat.size(); row < n; ++row) {
            int score = 0;
            for (int col = 0; col < cols; ++ col) {
                score += mat[row][col];
            }
            score = score * 1000 + row;
            orderedRows.push_back(make_pair(score, row));
        }
        
        sort(orderedRows.begin(), orderedRows.end());
        
        for (int i = 0; i < k; ++i) {
            result[i] = orderedRows[i].second;
        }
        
        return result;
    }
};