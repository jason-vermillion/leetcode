// https://leetcode.com/problems/champagne-tower/
// 799. Champagne Tower
// DP, pascal triangle, binomial coefficient
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // dp table for total champagne at each row and column pair in pyramid
        vector<vector<double>> glassTower(query_row + 1, vector<double>(query_row + 1, 0));
        double result = 0.0;
        
        glassTower[0][0] = poured;
        for (int row = 1; row <= query_row; ++row) {
            for (int col = 0; col <= row; ++col) {
                int left = col - 1;
                int right = col;
                double overflow = 0.0; // overflow from level above.
                
                if (left >= 0) {
                    overflow += max(0.0, glassTower[row - 1][left] - 1.0) / 2;
                }
                
                if (right < row) {
                    overflow += max(0.0, glassTower[row - 1][right] - 1.0) / 2;
                }
                
                glassTower[row][col] = overflow;
            }
        }
        
        //printDP(glassTower);
        result = min(1.0, glassTower[query_row][query_glass]);
        
        return result;
    }
    
    void printDP(vector<vector<double>>& dp) {
        int n = dp.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (j > 0) {
                    cout << ",";
                }
                cout << dp[i][j];
            }
            cout << endl;
        }
    }
};