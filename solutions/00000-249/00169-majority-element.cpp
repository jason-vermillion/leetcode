// https://leetcode.com/problems/majority-element/
// 169. Majority Element
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        int x = n / 2;
        int result = 0;
        
        for (auto v : nums) {
            freq[v]++;
        }
        
        for (auto p : freq) {
            if (p.second > x) {
                result = p.first;
                break;
            }
        }
        
        return result;
    }
};