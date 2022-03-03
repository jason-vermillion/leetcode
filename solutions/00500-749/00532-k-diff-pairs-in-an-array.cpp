// https://leetcode.com/problems/k-diff-pairs-in-an-array/
// O(n^2)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int result = 0;
        int sz = nums.size();
        set<pair<int,int>> uniquePairs;
        
        for (int i = 0; i < sz - 1; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                int absDiff = abs(nums[i] - nums[j]);
                if (absDiff == k) {
                    pair<int,int> p;
                    p.first = min(nums[i], nums[j]);
                    p.second = max(nums[i], nums[j]);
                    if (uniquePairs.count(p) == 0) {
                        result++;
                        uniquePairs.insert(p);
                    }
                }
            }
        }      
        return result;
    }
};



// https://leetcode.com/problems/k-diff-pairs-in-an-array/
// time complexity O(n)
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count = 0;
        int sz = nums.size();
        set<pair<int,int>> uniquePairs;
        unordered_map<int,int> freq;
        
        for (auto n : nums) {
            freq[n]++;
        }
        
        for (int i = 0; i < sz; ++i) {
            int b;
            int fb;
            pair<int,int> pair;
            
            b = nums[i] - k;
            fb = freq[b];
            if (b != nums[i] && fb > 0 || b == nums[i] && fb > 1) {
                pair = getOrderedPair(nums[i], b);
                if (uniquePairs.count(pair) == 0) {
                    uniquePairs.insert(pair);
                    count++;
                }
            }
            
            b = nums[i] + k;
            fb = freq[b];
            if (b != nums[i] && fb > 0 || b == nums[i] && fb > 1) {
                pair = getOrderedPair(nums[i], b);
                if (uniquePairs.count(pair) == 0) {
                    uniquePairs.insert(pair);
                    count++;
                }
            }
        }
        
        return count;
    }
private:
    pair<int,int> getOrderedPair(int a, int b) {
        pair<int,int> res;
        res.first = min(a, b);
        res.second = max(a, b);
        return res;
    }
};