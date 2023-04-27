// https://leetcode.com/problems/calculate-delayed-arrival-time/description/
// 2651. Calculate Delayed Arrival Time

class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        return (arrivalTime + delayedTime) % 24;
    }
};