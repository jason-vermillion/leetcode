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
        int n = nums.size();
        vector<int> res;
        unordered_map<int, int> xref; // value, index

        // O(n)
        for (int i = 0; i < n; ++i) {
            int a = nums[i];
            int b = target - a;
            if (xref.find(b) != xref.end()) {
                res.push_back(xref[b]);
                res.push_back(i);
                return res;
            }
            else {
                xref[a] = i;
            }
        }

        return res;
        
    }
};