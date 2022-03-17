// https://leetcode.com/problems/maximum-subarray/
// 53. Maximum Subarray
// kadane's algoorithm, DP
// Time complexity O(n)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum;
        int maxEndingHere;
        
        if (n == 0) return 0;
        
        maxEndingHere = nums[0];
        maxSum = nums[0];
        
        for (int i = 1; i < n; ++i) {
            maxEndingHere = max(maxEndingHere + nums[i], nums[i]);
            maxSum = max(maxEndingHere, maxSum);
        }
        
        return maxSum;
    }
    
    void printArr(vector<int>& arr) {
        cout << "[";
        for (int i = 0; i < arr.size(); ++i) {
            if (i > 0) {
                cout << ",";
            }
            cout << arr[i];
        }
        cout << "]\n";
    }
};