// https://leetcode.com/problems/permutation-in-string/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freqS1(26, 0);
        vector<int> freqSub(26, 0);
        
        for (auto c : s1) {
            int a = c - 'a';
            freqS1[a]++;
        }
        
        int lenS1 = s1.size();
        int lenS2 = s2.size();
        for (int i = 0; i < lenS2 - lenS1 + 1; ++i) {
            reset(freqSub);
            for (int j = i; j < i + lenS1; ++j) {
                int a = s2[j] - 'a';
                freqSub[a]++;
            }
            if (freqS1 == freqSub) {
                return true;
            }
        }
        
        return false;
    }
    
private:
    void reset(vector<int>& freqSub) {
        for (int i = 0; i < 26; ++i) {
            freqSub[i] = 0;
        }
    }
};