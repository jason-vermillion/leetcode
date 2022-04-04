// https://leetcode.com/problems/next-permutation/
// 31. Next Permutation
// https://medium.com/trick-the-interviwer/next-greater-permutation-bb12e014e797
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int x = -1, y = 0;
        int n = nums.size();
        
        for (x = n - 2; x >= 0; x--) {
            if (nums[x] < nums[x+1]) {
                break;
            }
        }
        
        if (x < 0) {
            reverse(nums.begin(), nums.end());
        }
        else {
            for (y = n - 1; y > x; y--) {
                if (nums[x] < nums[y]) {
                    break;
                }
            }
            
            swap(nums[x], nums[y]);
            reverse(nums.begin() + x + 1, nums.end());
        }
    }
};