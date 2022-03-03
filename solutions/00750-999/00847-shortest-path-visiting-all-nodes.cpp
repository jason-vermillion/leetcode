// https://leetcode.com/problems/shortest-path-visiting-all-nodes/
// 847. Shortest Path Visiting All Nodes
// bread first search to find shortest path and bit masking to track visited nodes
// bfs
class Solution {
private:
    class Path {
    public:
        int node = 0;
        int visitedMask = 0;
        int totalCost = 0;
                
        Path(int node, int visitedMask, int totalCost) {
            this -> node = node;
            this -> visitedMask = visitedMask;
            this -> totalCost = totalCost;
        }
    };
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(); // nodes in graph
        set<pair<int,int>> visitedPaths;
        queue<Path> bfsQ;
        const int ALL_NODES = (1 << n) - 1; // bit mask for all possible nodes in graph
        
        for (int i = 0; i < n; ++i) {
            int mask = 1 << i;
            visitedPaths.insert(make_pair(i, mask));
            bfsQ.push(Path(i, mask, 0));
        }
        
        while(!bfsQ.empty()) {
            Path curr = bfsQ.front();
            bfsQ.pop();
            
            if (curr.visitedMask == ALL_NODES) {
                return curr.totalCost;
            }
            
            // iterate and add adjacent nodes to search queue.
            for (auto adj : graph[curr.node]) {
                int newMask = curr.visitedMask | (1 << adj);
                
                Path newPath(adj, newMask, curr.totalCost + 1);
                pair<int,int> newVisited = make_pair(adj, newMask);
                
                if (visitedPaths.count(newVisited) == 0) {
                    bfsQ.push(newPath);
                    visitedPaths.insert(newVisited);
                }
            }
        }
        
        return -1;
    }
};