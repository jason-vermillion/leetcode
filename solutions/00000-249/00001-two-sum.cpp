class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int max = nums.size();
        
        // brute force O(n^2)
        for (int i = 0; i < max - 1; i++) {
            for (int j = i + 1; j < max; j++) {
                if (nums.at(i) + nums.at(j) == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        
        return result;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> freq;
        int diff = 0;
        int val = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            val = nums.at(i);
            diff = target - val;
            if (freq.count(diff) > 0) {
                result.push_back(freq[diff]);
                result.push_back(i);
                return result;
            }
            else {
                freq[val] = i;
            }
        }
        
        return result;
    }
};