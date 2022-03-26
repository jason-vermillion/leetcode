// https://leetcode.com/problems/binary-search/
// 704. Binary Search
// Time complexity O(logN)
// binary search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index = -1;
        int start, mid, end;
        
        start = 0;
        end = nums.size() - 1;
        mid = end / 2;
        
        while(start <= end) {
            if (nums[mid] == target) {
                index = mid;
                break;
            }
            
            if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
            //mid = (start + end) / 2 ;
            mid = start + (end - start) / 2;
        }
        
        return index;
    }
};