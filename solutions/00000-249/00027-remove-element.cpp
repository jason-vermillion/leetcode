// https://leetcode.com/problems/remove-element/
// 27. Remove Element
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int delCount = 0;
        int prevI;
        int sz;
        
        if (nums.size() == 0) {
            return 0;
        }
        
        prevI = 0;
        sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            if (nums[i] == val) {
                delCount++;
            }
            else {
                if (prevI < i) {
                    nums[prevI] = nums[i];
                }
                prevI++;
            }
        }
        
        k = sz - delCount;
        
        return k;
    }
};