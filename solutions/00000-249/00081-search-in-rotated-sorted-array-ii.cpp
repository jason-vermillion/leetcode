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
            
            // sorted segment, normal binary search
            if (nums[start] <= nums[mid] && nums[mid] <= nums[end] && target > nums[mid] && target <= nums[end]) {
                start = mid + 1;
            }
            else if (nums[start] <= nums[mid] && nums[mid] <= nums[end] && target >= nums[start] && target < nums[mid]) {
                end = mid - 1;
            }
            
            // try to find a sorted segment to continue the binary search
            else if (nums[mid] <= nums[end] && target > nums[mid] && target <= nums[end]) {
                start = mid + 1;
            }
            else if (nums[start] <= nums[mid] && target >= nums[start] && target < nums[mid]) {
                end = mid - 1;
            }
            else {
                if (target == nums[start]) return true;
                
                start++;
            }
            
        }
        
        return false;
        
    }
};