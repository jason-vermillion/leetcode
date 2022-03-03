// https://leetcode.com/problems/arithmetic-slices/
// 413. Arithmetic Slices
// Time complexity O(n)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int total = 0;
        int currCount = 0;
        int n = nums.size();
        
        if (n < 3) return 0;
                
        for (int i = 2; i < n; ++i) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                currCount++;
                total = total + currCount;
            }
            else {
                currCount = 0;
            }
        }
        
        return total;
    }
};