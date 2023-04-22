// 88. https://leetcode.com/problems/merge-sorted-array/
// O(N)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp1(m, -1);

        // copy the nums1 to a working temp since nums1 is overwritten for output.
        for (int i = 0; i < m; ++i) {
            temp1[i] = nums1[i];
        }

        int x = 0;
        for (int i = 0, j = 0; i < m || j < n; ) {
            if (j > n - 1) {
                nums1[x] = temp1[i];
                i++;
            }
            else if (i > m - 1) {
                nums1[x] = nums2[j];
                j++;
            }
            else if (temp1[i] <= nums2[j]) {
                nums1[x] = temp1[i];
                i++;
            }
            else {
                nums1[x] = nums2[j];
                j++;
            }
            x++;
        }
    }
};