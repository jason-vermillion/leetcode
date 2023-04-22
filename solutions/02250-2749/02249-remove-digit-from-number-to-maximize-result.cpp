// https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/
// 2259. Remove Digit From Number to Maximize Result
class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        vector<string> permutations;

        for (int i = 0; i < n; i++) {
            string t;
            if (number[i] == digit) {
                t = number.substr(0, i) + number.substr(i+1, n-i-1);
                permutations.push_back(t);
            }
        }

        sort(permutations.begin(), permutations.end());

        return permutations[permutations.size()-1];
    }
};