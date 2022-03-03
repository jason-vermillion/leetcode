// https://leetcode.com/problems/subsets/
// https://en.wikipedia.org/wiki/Power_set
// time complexity O(N)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int sz = nums.size();
        vector<vector<int>> powerSets;
        int maxCounter = pow(2, sz);

        for (int i = 0; i < maxCounter; ++i) {
            vector<int> subset;
            
            for (int j = 0; j < sz; ++j) {
                if ((i >> j) & 1) {
                    subset.push_back(nums[j]);
                }
            }
            powerSets.push_back(subset);
        }
        
        return powerSets;
    }
};