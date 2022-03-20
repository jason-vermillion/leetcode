// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
// 1007. Minimum Domino Rotations For Equal Row
// Time complexity O(N)

// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
// 1007. Minimum Domino Rotations For Equal Row
// Time complexity O(N)

class Solution {
public:
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> a(7);
        vector<int> b(7);
        vector<int> same(7);
        int n = tops.size();
        
        for (int i = 0; i < n; ++i) {
            a[tops[i]]++;
            b[bottoms[i]]++;
            
            if (tops[i] == bottoms[i]) {
                same[tops[i]]++;
            }
        }
                
        for (int i = 1; i < 7; ++i) {
            if (a[i] + b[i] - same[i] == n) {
                return min(n - a[i], n - b[i]);
            }
        }
        
        return -1;
    }    
};



// alternate solution
class Solution {
public:
    struct Stats {
        int value;
        int count;
        int topCount;
        int bottomCount;
        
        Stats () {
            value = 0;
            count = 0;
            topCount = 0;
            bottomCount = 0;
        }
    };
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        Stats aStats;
        Stats bStats;
        int n = tops.size();
        int count = INT_MAX;
        
        if (tops.size() == 0 || bottoms.size() == 0) return 0;
        
        // common value has to be either the top or bottom of first domino
        aStats.value = tops[0];        
        bStats.value = bottoms[0];
        
        if (tops[0] == bottoms[0]) bStats.value = INT_MIN;
        
        for (int i = 0; i < n; ++i) {
            if (tops[i] == aStats.value || bottoms[i] == aStats.value) {
                aStats.count++;
                if (tops[i] == aStats.value) aStats.topCount++;
                if (bottoms[i] == aStats.value) aStats.bottomCount++;
            }
            if (tops[i] == bStats.value || bottoms[i] == bStats.value) {
                bStats.count++;
                if (tops[i] == bStats.value) bStats.topCount++;
                if (bottoms[i] == bStats.value) bStats.bottomCount++;
            }
        }
        
        if (aStats.count == n) {
            count = min(n - aStats.topCount, n - aStats.bottomCount);
        }
        else if (bStats.count == n) {
            count = min(count, min(n - bStats.topCount, n - bStats.bottomCount));
        }
        else {
            count = -1;
        }
        
        return count;
    }
};