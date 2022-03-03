// https://leetcode.com/problems/excel-sheet-column-number/
// 171. Excel Sheet Column Number
// number base 26 problem
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        int n = columnTitle.size();
        
        for (int i = 0; i < n; ++i) {
            int x = columnTitle[i] - 'A' + 1;
            res = res * 26 + x;
        }
        
        return res;
    }
};