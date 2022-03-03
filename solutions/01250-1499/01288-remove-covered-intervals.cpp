// https://leetcode.com/problems/remove-covered-intervals/
// 1288. Remove Covered Intervals
// Time complexity O(N log N)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int z = n;
        int start;
        int end;
        
        if (intervals.size() < 2) {
            return n;
        }
        
        sort(intervals.begin(), intervals.end(), sorter);
        start = intervals[0][0];
        end = intervals[0][1];
        //printArr(intervals);
        
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] >= start && intervals[i][1] <= end) {
                z--;
            }
            
            if (intervals[i][1] > end) {
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        
        return z;
    }
private:
    static bool sorter(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        else {
            return a[0] < b[0];
        }
    };

    void printArr(vector<vector<int>>& arr) {
        cout << "[";
        for (int i = 0; i < arr.size(); ++i) {
            if (i > 0) cout << ",";
            cout << "[";
            for (int j = 0; j < arr[i].size(); ++j) {
                if (j > 0) cout << ",";
                cout << arr[i][j];
            }
            cout << "]";
        }
        cout << "]\n";
    }
};

// https://leetcode.com/problems/remove-covered-intervals/
// 1288. Remove Covered Intervals
// out of memory heap error
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> times;
        int n = intervals.size();
        int z = n;
        
        for (int i = 0; i < n; ++i) {
            times.push_back(vector<int>(10000,0));
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = intervals[i][0]; j <= intervals[i][1]; ++j) {
                times[i][j] = 1;
            }
        }
        
        for (int i = 0; i < n; ++i) {
            int a = intervals[i][0];
            int b = intervals[i][1];
            for (int j = 0; j < n; ++j) {
                // check if interval[i] is covered by another.
                if (j != i && times[j][a] == 1 && times[j][b] == 1) {
                    z--;
                    break;
                }
            }
        }
        
        return z;
    }
};