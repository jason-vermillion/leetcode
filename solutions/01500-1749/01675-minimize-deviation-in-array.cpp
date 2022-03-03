// https://leetcode.com/problems/minimize-deviation-in-array/
// 1675. Minimize Deviation in Array
// using a priority queue.
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> highestVals;
        int sz;
        int minVal = INT_MAX;
        int minDev = INT_MAX;
        
        // double all the odd values.
        sz = nums.size();
        for (int i = 0; i < sz; ++i) {
            if (nums[i] % 2 != 0) {
                nums[i] = nums[i] * 2;
            }
        }
        
        // insert into priority queue with highest value at the top of the queue.
        for (int i = 0; i < sz; ++i) {
            minVal = min(minVal, nums[i]);
            highestVals.push(nums[i]);
        }
        
        minDev = highestVals.top() - minVal;
        
        // keep reducing the highest value to find the minimum deviation.
        while(highestVals.top() % 2 == 0) {
            int curr = highestVals.top();
            int diff = curr - minVal;
            
            minDev = min(minDev, diff);
            curr = curr / 2;
            
            highestVals.pop();
            highestVals.push(curr);
            
            minVal = min(minVal, curr);
        }
        
        minDev = min(minDev, highestVals.top() - minVal);
        
        return minDev;
    }
};