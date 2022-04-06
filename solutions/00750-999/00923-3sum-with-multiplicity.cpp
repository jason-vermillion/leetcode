// https://leetcode.com/problems/3sum-with-multiplicity/
// 923. 3Sum With Multiplicity
// https://mathworld.wolfram.com/BinomialCoefficient.html
class Solution {
public:
    #define ll long long
    int threeSumMulti(vector<int>& arr, int target) {
        const int BIG_MOD = 1e9+7;
        vector<long long> freq(101, 0);
        long long result = 0;
        
        for (auto val : arr) {
            freq[val]++;
        }
        
        for (int i = 0; i < 101; ++i) {
            if (3 * i == target) {
                // freq[i] C 3 = freq[i]! / (3! * (freq[i] - 3)!)
                result += freq[i] * (freq[i] - 1) * (freq[i] - 2) / 6;
                result = result % BIG_MOD;
            }
            for (int j = i + 1; j < 101; ++j) {
                int k = target - i - j;
                
                if (target == 2 * i + j) {
                    // freq[j] * (freq[i] C 2) = freq[j] * freq[i]! / (2! * (freq[i] - 2)!)
                    result += freq[i] * (freq[i] - 1) * freq[j] / 2;
                }
                else if (target == 2 * j + i) {
                    // freq[i] * (freq[j] C 2)
                    result += freq[j] * (freq[j] - 1) * freq[i] / 2;
                }
                else if (j < k && k < 101 && target == i + j + k) {
                    // i < j < k && target == i + j + k
                    result += freq[i] * freq[j] * freq[k];
                }
                result = result % BIG_MOD;
            }
        }
        
        return result;
    }
    
    //printVector(freq);
    //printf("i: %d, j: %d, k: %d, result: %d\n", i, j, k, result);
    void printVector(vector<int>& arr) {
        int n = arr.size();
        cout << "[";
        
        for (int i = 0; i < n; ++i) {
            if (i > 0) cout << ",";
            
            cout << arr[i];
        }
        
        cout << "]\n";
    }
    
};