// https://leetcode.com/problems/search-a-2d-matrix/
// 74. Search a 2D Matrix
// Time complexity O(logN)
// space complexity O(1)
// Treat the maxtrix as a 1-dimensional array and do a standard binary search.
// Use div and mod math to get the row/col of the cell
class Solution {
public:
    struct Point {
        public:
        int row;
        int col;
        
        Point () {
            row = 0;
            col = 0;
        }
    };
    
    Point* getPoint(int index, int rows, int cols) {
        Point* p = new Point();
        p -> row = index / cols;
        p -> col = index % cols;
        
        return p;
    }

    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows, cols;
        int left, right, mid;
        
        rows = matrix.size();
        if (rows == 0) return false;
        cols = matrix[0].size();
        
        left = 0;
        right = rows * cols - 1;
        
        while (left <= right) {
            Point* leftP;
            Point* rightP;
            Point* midP;
            mid = left + (right - left) / 2;
            
            leftP = getPoint(left, rows, cols);
            rightP = getPoint(right, rows, cols);
            midP = getPoint(mid, rows, cols);
                        
            if (matrix[midP -> row][midP -> col] == target) {
                return true;
            }
            
            if (matrix[leftP -> row][leftP -> col] <= target && target < matrix[midP -> row][midP -> col]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        
        return false;
    }
    
};
/*
            printf("left: %d, mid: %d, right: %d,", left, mid, right);
            printf(" leftP(%d, %d), midP(%d, %d), rightP(%d, %d)\n",
                   leftP -> row, leftP -> col, midP -> row, midP -> col, rightP -> row, rightP -> col);
*/