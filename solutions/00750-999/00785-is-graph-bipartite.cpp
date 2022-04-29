// https://leetcode.com/problems/is-graph-bipartite/
// 785. Is Graph Bipartite?
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n);

        for(int i = 0; i < n; i++) {
            if(visited[i]) continue;

            queue<int> q;
            q.push(i);
            visited[i] = 1;

            while(!q.empty())
            {
                int parent = q.front();
                q.pop();
                for(auto child : graph[parent]) {
                    if(visited[child] == 0) {
                        visited[child] = -visited[parent];
                        q.push(child);
                    }
                    else if (visited[parent] == visited[child]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};