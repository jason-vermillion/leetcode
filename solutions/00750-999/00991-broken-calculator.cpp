// https://leetcode.com/problems/broken-calculator/
// 991. Broken Calculator
class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int count = 0;
        int s = startValue;
        int t = target;
        
        while (t > s) {
            if (t % 2 == 0) {
                t = t / 2;
            }
            else {
                t = t + 1;
            }
            count++;
        }
        
        count = count + (s - t);
        
        return count;
    }
};