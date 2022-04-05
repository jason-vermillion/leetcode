// https://leetcode.com/problems/largest-rectangle-in-histogram/
// 84. Largest Rectangle in Histogram
// max area monotonic stack
// TODO: revisit
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        stack<int> s;
        int maxArea = 0;
        int top = 0;
        int w = 0;
        int h = 0;
        int area = 0;
        
        
        for(int i = 0; i <= size; i++){
            h = 0;
            if (i < size) {
                h = heights[i];
            }
            
            while(!s.empty() && h < heights[s.top()]) {
                top = s.top();
                s.pop();
                if (s.empty()) {
                    w = i;
                }
                else {
                    w = i - s.top() - 1;
                }

                area = heights[top] * w;
                
                maxArea = max(area, maxArea);
            }
            
            s.push(i);
        }
        return maxArea;
    }
};