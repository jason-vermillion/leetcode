// https://leetcode.com/problems/rotate-array/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        int x = 0;
        vector<int> rotated(size, 0);
        
        for (int i = 0; i < size; ++i) {
            x = (i + k) % size;
            rotated[x] = nums[i];
        }
        
        for (int i = 0; i < size; ++i) {
            nums[i] = rotated[i];
        }
    }
};