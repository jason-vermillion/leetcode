// https://leetcode.com/problems/k-closest-points-to-origin/
// 973. K Closest Points to Origin
// time complexity O(NLogN)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> result(k, vector<int>(2));
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) -> bool {
            return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
        });
        
        for (int i = 0; i < k; ++i) {
            result[i][0] = points[i][0];
            result[i][1] = points[i][1];
        }
        
        return result;
    }
};