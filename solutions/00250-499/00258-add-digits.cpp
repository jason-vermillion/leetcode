// https://leetcode.com/problems/add-digits/
class Solution {
public:
    int addDigits(int num) {
        int sum = sumDigits(num);
        
        while(sum >= 10) {
            sum = sumDigits(sum);
        }
        
        return sum;
    }
    
private:
    int sumDigits(int num) {
        int x = num;
        int sum = 0;
        
        while (x > 0) {
            sum += x % 10;
            x = x / 10;
        }
        
        return sum;
    }
};