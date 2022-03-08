// https://leetcode.com/problems/linked-list-cycle/
// 141. Linked List Cycle
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        set<ListNode*> visited;
        ListNode* curr = head;
                
        while (curr != nullptr) {
            if (visited.count(curr) != 0) {
                return true;
            }
            visited.insert(curr);
            curr = curr -> next;
        }
        
        return false;
    }
};