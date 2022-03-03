// https://leetcode.com/problems/search-insert-position/
// 35. Search Insert Position
// binary search
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low, high, mid;
        
        if (nums.size() == 0) return 0;
        
        low = 0;
        high = nums.size() - 1;
        
        if (target < nums[0]) return 0;
        if (target > nums[high]) return high + 1;
                
        while (low < high) {
            mid = low + (high - low) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        if (nums[high] < target) {
            high++;
        }
        
        return high;
    }
};