// https://leetcode.com/problems/contiguous-array/
// time complexity O(n)
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> sumPositions;
        int sum = 0;
        int maxLen = 0;
        
        sumPositions[0] = -1;
        
        for (int i = 0; i < nums.size(); ++i) {
            int curLen = 0;
            // increment the sum if 1, decrement if 0
            sum += (nums[i]==0) ? -1 : 1;
            
            // check the map if there is a corresponding sum
            if (sumPositions.count(sum) > 0) {
                curLen = i - sumPositions[sum];
                if (curLen > maxLen) {
                    maxLen = curLen;
                }
            }
            else {
                sumPositions[sum] = i;
            }
        }
        return maxLen;
    }
};


// https://leetcode.com/problems/contiguous-array/
// time complexity O(n^2) - TLE
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int> leftSum;
        int window = 0;
        
        leftSum = getLeftSum(nums);
        
        // window is divisible by 2
        window = (nums.size() % 2 == 0) ? nums.size() : nums.size() - 1;
        
        // from the largest possible window down to 2
        while(window > 1) {
            for (int i = 0; i <= nums.size() - window; ++i) {
                int curSum = -1;
                int left = 0;
                
                if (i > 0) {
                    left = leftSum[i-1];
                }
                
                curSum = leftSum[i + window -1] - left;
                if (curSum == 0) {
                    return window;
                }
            }
            window = window - 2;
        }

        // no window found with even number of 1s and 0s
        return 0;
    }
private:
    vector<int> getLeftSum(vector<int>& nums) {
        vector<int> leftSum(nums.size(), -1);
        
        int tot = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                tot--;
            }
            else if (nums[i] == 1) {
                tot++;
            }
            leftSum[i] = tot;
        }
        
        return leftSum;
    }
    
    void printArray(vector<int>& nums) {
        cout << "[";
        for (auto val : nums) {
            cout << val << ",";
        }
        cout << "]\n";
    }
        
};