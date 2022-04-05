// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
// 2226. Maximum Candies Allocated to K Children
// Time complexity O(NlogN)
// Space complexity O(1)
// binary search, greedy
class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int result = 0;
        int n = candies.size();
        int left=1, mid, right = *max_element(candies.begin(), candies.end());
        long long total = 0;
        
        while (left <= right) {
            mid = left + (right - left) / 2;
            
            total = 0;
            for (int i = 0; i < n; ++i) {
                total = total + candies[i] / mid;
            }
            
            if (total >= k) {
                result = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return result;
        
    }
};