class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        bool isMountain = true;
        bool isAscending = true;
        int prev = -1;
        int max = -1;
        int m = arr.size();
        
        if (m < 3) {
            return false;
        }
        
        for (int i = 0; i < m; i++) {
            if (arr[i] == prev) {
                return false;
            }
            if (isAscending && arr[i] < prev) {
                isAscending = false;
            }
            else if (!isAscending && arr[i] >= prev) {
               return false;
            }
            prev = arr[i];
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        
        if (prev == max || arr[0] == max) {
            isMountain = false;
        }
        
        
        return isMountain;
        
    }
};