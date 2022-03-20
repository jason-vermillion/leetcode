// https://leetcode.com/problems/sqrtx/
// 69. Sqrt(x)
// https://leetcode.com/problems/sqrtx/
// 69. Sqrt(x)

// binary search method O(logN)
class Solution {
public:
    int mySqrt(int x) {
        int start = 1;
        int end = x;
        int mid = end / 2;
        
        if (x <= 1) return x;
        //printf("start: %d, mid: %d, end: %d\n", start, mid, end);
        while (start <= end) {
            // mid * mid <= x && (mid + 1)(mid + 1) > x
            if (mid <= x / mid && mid > x / (mid + 1) - 1) {
                return mid;
            }
            // mid * mid < x
            else if (mid < x / mid) {
                start = mid + 1;
                mid = start + (end - start) / 2;
            }
            else {
                end = mid - 1;
                mid = mid / 2;
            }
            //printf("start: %d, mid: %d, end: %d\n", start, mid, end);
        }
        
        return 0;
    }
};


/*
// brute force method O(sqrt(n))
class Solution {
public:
    int mySqrt(int x) {
        int result = 0;
        int n;
        
        if (x <= 1) return x;
        
        for (int i = 1; i <= x / i; ++i) {
            // i*i <= x And (i+1)(i+1) > x
            if (i <= x / i && i > x / (i+1) - 1) {
                return i;
            }
        }
        
        return -1;
    }
};
*/
