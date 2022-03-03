class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        int p = 0;
        int leadingDigit = 0;
        int num = 0;
        
        leadingDigit = low;
        while (leadingDigit >= 10) {
            leadingDigit = leadingDigit / 10;
            p++;
        }
        cout << "leading digit = " << leadingDigit << endl;
        cout << "p = " << p << endl;
        
        for (int i = 1; i <= p; i++) {
            num = num * 10 + i;
        }
        
        cout << num;
        
        return res;
    }
};