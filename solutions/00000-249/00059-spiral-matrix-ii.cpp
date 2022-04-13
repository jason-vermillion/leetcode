// https://leetcode.com/problems/spiral-matrix-ii/
// 59. Spiral Matrix II
// Time complexity O(N^2)
// Space complexity O(1)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int row = 0, col = 0;
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        int val = 1;
        
        while (top <= bottom && left <= right) {
            // right
            row = top;
            for (int col = left; col <= right; col++) {
                matrix[row][col] = val;
                val++;
            }
            
            // down
            col = right;
            for (int row = top + 1; row <= bottom; row++) {
                matrix[row][col] = val;
                val++;
            }
            
            // left
            row = bottom;
            for (col = right - 1; col >= left; col--) {
                matrix[row][col] = val;
                val++;
            }
            
            // up
            col = left;
            for (row = bottom - 1; row > top; row--) {
                matrix[row][col] = val;
                val++;
            }
            
            left++;
            right--;
            top++;
            bottom--;
        }
        
        return matrix;
    }
};