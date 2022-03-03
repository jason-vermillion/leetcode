// https://leetcode.com/problems/summary-ranges/
// 228. Summary Ranges
class Solution {
private:
    string rangeTostring(int a, int b) {
        string token;
        if (a == b) {
            token = to_string(a);
        }
        else {
            token = to_string(a) + "->" + to_string(b);
        }
        
        return token;
    }
public:
    vector<string> summaryRanges(vector<int>& nums) {
        string range;
        vector<string> result;
        int a, b;
        int n;
        bool inRange = false;
        
        n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                a = nums[i];
                inRange = true;
            }
            else if (nums[i] > nums[i - 1] + 1) {
                result.push_back(rangeTostring(a, b));
                a = nums[i];
                inRange = true;
            }
            b = nums[i];
        }
        
        if (inRange) {
            result.push_back(rangeTostring(a,b));
        }
        
        return result;
    }
};