// https://leetcode.com/problems/copy-list-with-random-pointer/
// 138. Copy List with Random Pointer
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodeMap; // lookup for the new copy based on reference to original node.
        Node* curr;
        Node* curr2;
        Node* newTail;
        Node* dummy;
        
        dummy = new Node(INT_MIN);
        newTail = dummy;
        curr = head;
        while(curr != nullptr) {
            Node* copy = new Node(curr -> val);
            newTail -> next = copy;
            
            if (nodeMap.count(curr) == 0) {
                nodeMap[curr] = copy;
            }
            
            curr = curr -> next;
            newTail = newTail -> next;
        }
        
        curr = head;
        curr2 = dummy -> next;
        while (curr != nullptr) {
            if (curr -> random != nullptr) {
                curr2 -> random = nodeMap[curr -> random];
            }
            
            curr = curr -> next;
            curr2 = curr2 -> next;
        }
        
        return dummy -> next;
        
    }
};