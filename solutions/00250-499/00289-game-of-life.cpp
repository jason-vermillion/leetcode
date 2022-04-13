// https://leetcode.com/problems/game-of-life/
// 289. Game of Life
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = (m > 0) ? board[0].size() : 0;
        vector<vector<int>> c(m+2, vector<int>(n+2));

        // clone the board, one extra 0 cell around the outside
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                c[i+1][j+1] = board[i][j];
            }
        }
        
        for (int i = 1; i < m+1; ++i) {
            for (int j = 1; j < n+1; ++j) {
                int count = 0;
                count += c[i-1][j-1];
                count += c[i-1][j];
                count += c[i-1][j+1];
                count += c[i][j-1];
                count += c[i][j+1];
                count += c[i+1][j-1];
                count += c[i+1][j];
                count += c[i+1][j+1];
                
                if (count < 2) {
                    board[i-1][j-1] = 0;
                }
                else if (count > 3) {
                    board[i-1][j-1] = 0;
                }
                else if (c[i][j] == 0 && count == 3) {
                    board[i-1][j-1] = 1;
                }
            }
        }
    }
    
    void printArr(vector<vector<int>>& arr) {
        cout << "[";
        for (int i = 0; i < arr.size(); ++i) {
            if (i > 0) cout << ",";
            cout << "[";
            for (int j = 0; j < arr[0].size(); ++j) {
                if (j > 0) cout << ",";
                cout << arr[i][j];
            }
            cout << "]";
        }
        cout << "]\n";
    }
};