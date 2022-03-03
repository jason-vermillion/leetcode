// https://leetcode.com/problems/clone-graph/
// 133. Clone Graph
// bfs search using a queue

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    bool hasNeighbor(Node* node, int val) {
        for (auto neighbor : node -> neighbors) {
            if (neighbor -> val == val) {
                return true;
            }
        }
        return false;
    }
public:
    Node* cloneGraph(Node* node) {
        vector<bool> visited(110, false);
        Node* clone;
        unordered_map<int, Node*> nodeLookup;
        int val;
        queue<Node*> searchQ;
        
        if (node == nullptr) {
            return nullptr;
        }
        
        if (node -> neighbors.size() == 0) {
            return new Node(node -> val);
        }
        
        val = node -> val;
        clone = new Node(val);
        nodeLookup[val] = clone;
        
        searchQ.push(node);
        
        // bfs search using queue
        while(!searchQ.empty()) {
            Node* curr = searchQ.front();
            searchQ.pop();
            
            val = curr -> val;
            visited[val] = true;
            
            // clone the node
            Node* copyNode = nodeLookup[val];
            for (auto neighbor : curr -> neighbors) {
                Node* neighborCopy;
                if (nodeLookup[neighbor -> val] == nullptr) {
                    neighborCopy = new Node(neighbor -> val);
                    nodeLookup[neighbor -> val] = neighborCopy;
                }
                else {
                    neighborCopy = nodeLookup[neighbor -> val];
                }
                
                if (!hasNeighbor(copyNode, neighbor -> val)) {
                    copyNode -> neighbors.push_back(neighborCopy);    
                }
                
            }
            
            // add the adjacent nodes to the search q.
            for (auto adj : curr -> neighbors) {
                if (!visited[adj -> val]) {
                    searchQ.push(adj);
                }
            }
        }
        
        return clone;
        
    }
};