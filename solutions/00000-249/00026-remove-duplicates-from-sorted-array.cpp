// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// 26. Remove Duplicates from Sorted Array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int newLen = 0;
        int delCount = 0;
        int prev;
        int prevI;
        
        if (nums.size() <= 1) {
            return nums.size();
        }
        
        prev = nums[0];
        prevI = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == prev) {
                delCount++;
            }
            else if (nums[i] != prev) {
                if (i > prevI + 1) {
                    nums[prevI + 1] = nums[i];    
                }
                prev = nums[i];
                prevI = prevI + 1;
            }
        }
        
        newLen = nums.size() - delCount;
        return newLen;
    }
};