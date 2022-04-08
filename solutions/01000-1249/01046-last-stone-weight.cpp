// https://leetcode.com/problems/last-stone-weight/
// 1046. Last Stone Weight
// Time complexity O(NlogN) priority_queue is logN per inserstion or deletion
// Space complexity O(N)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq;
        int a, b;
        int result = 0;
        
        for (int val : stones) {
            pq.push(val);
        }
        
        while(pq.size() > 1) {
            b = pq.top();
            pq.pop();
            a = pq.top();
            pq.pop();
            
            if (a != b) {
                pq.push(b - a);
            }
        }
        
        if (pq.size() > 0) {
            result = pq.top();
        }
        return result;
    }    
};