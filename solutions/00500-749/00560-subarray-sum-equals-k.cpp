// https://leetcode.com/problems/subarray-sum-equals-k/
// contiguous sum sub array
// time complexity O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int total = 0;
        unordered_map<int,int> sums;
        int sz;
        
        sums[0] = 1; // zero sum
        
        sz = nums.size();
        for(int i = 0; i < sz; ++i) {
            total += nums[i];
            int a = total - k;
            
            if (sums[a] > 0) {
                count += sums[a];
            }
            sums[total]++;
            //printf("i: %d, total: %d, a: %d, count: %d\n", i, total, a, count);
        }
        
        return count;
    }
};