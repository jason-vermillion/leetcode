// https://leetcode.com/problems/partition-labels/
// 763. Partition Labels
// Time complexity O(n)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastCharIndex(26);
        vector<int> segments;
        char c;
        int n = s.size();
        int prev;
        int maxSoFar;
        
        for (int i = 0; i < n; ++i) {
            c = s[i] - 'a';
            lastCharIndex[c] = i;
        }
        
        prev = -1;
        maxSoFar = 0;
        for (int i = 0; i < n; ++i) {
            c = s[i] - 'a';
            int curr = lastCharIndex[c];
            maxSoFar = max(maxSoFar, curr);
            if (i == maxSoFar) {
                segments.push_back(i - prev);
                prev = i;
            }
        }
        
        return segments;
    }
};