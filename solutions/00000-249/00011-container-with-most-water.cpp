// https://leetcode.com/problems/container-with-most-water/
// 11. Container With Most Water
// Time complexity O(N)
// Space complexity O(1)
// greedy two pointer
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0, area;
        int left = 0, right = height.size() - 1;
        
        while (left < right) {
            area = (right - left) * min(height[left], height[right]);
            maxArea = max(maxArea, area);
            
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        
        return maxArea;
    }
};