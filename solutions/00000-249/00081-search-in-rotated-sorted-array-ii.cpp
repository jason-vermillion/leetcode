// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/submissions/
// 81. Search in Rotated Sorted Array II
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int start, mid, end;
        
        start = 0;
        end = nums.size() - 1;
        
        while (start <= end) {
            mid = start + (end - start) / 2;
            
            if (nums[mid] == target) {
                return true;
            }
            
            if (nums[start] < nums[mid]) {
                if (nums[start] <= target && target < nums[mid]) {
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
            else if (nums[start] == nums[mid]) {
                start++;
            }
            else {
                if (target > nums[mid] && target <= nums[end]) {
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
        }
        
        return false;
        
    }
};