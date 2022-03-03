// https://leetcode.com/problems/4sum-ii/
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sumsA;
        int sumCount = 0;
        
        for (auto a : nums1) {
            for (auto b : nums2) {
                int sum1 = a + b;
                if (sumsA.count(sum1) > 0) {
                    sumsA[sum1]++;
                }
                else {
                    sumsA[sum1] = 1;
                }
            }
        }
        
        for (auto c : nums3) {
            for (auto d : nums4) {
                int sum2 = c + d;
                
                if (sumsA.count(-sum2) > 0) {
                    sumCount += sumsA[-sum2];
                }
            }
        }
        
        return sumCount;
    }
};