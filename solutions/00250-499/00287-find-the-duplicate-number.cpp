// https://leetcode.com/problems/find-the-duplicate-number/
// 287. Find the Duplicate Number
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n+1);
        
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            if (freq[val] > 0) {
                return val;
            }
            freq[val]++;
        }
        
        return -1;
    }
};