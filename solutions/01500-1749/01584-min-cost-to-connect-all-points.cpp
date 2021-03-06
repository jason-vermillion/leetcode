// https://leetcode.com/problems/min-cost-to-connect-all-points/
// 1584. Min Cost to Connect All Points
// MST, minimum spanning tree, kruskal, minheap
class Solution {
public:
    
    int find(vector<int>& parents, int i) {
        
        if(parents[i] == i){
            return i;
        }
        
        parents[i] = find(parents, parents[parents[i]]);
        
        return parents[i];
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> parents(n, 0);
        int distance = 0;
        int edges = 0;
        priority_queue<vector<int>> pq;
        
        for (int i = 1; i < n; ++i) {
            parents[i] = parents[i - 1] + 1; 
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(i != j){
                     pq.push({-1*(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])), i, j});
                }
            }
        }
        
        while(edges != n - 1) {
            vector<int> edge = pq.top();
            
            int p1 = find(parents, edge[1]);
            int p2 = find(parents, edge[2]);
            
            if(p1 != p2){
                
                distance += -1 * edge[0];
                
                parents[p1] = p2;
                
                edges++;
            }
            
            pq.pop();
        }
        
        return distance;
    }
};