// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
// 1721. Swapping Nodes in a Linked List
// Time complexity O(N)
// space comlexity O(1)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        ListNode *a = nullptr, *b = nullptr, *curr = nullptr;
        
        if (head == nullptr || head -> next == nullptr) return head;
        
        // run in a single pass, set b to head when a reaches the kth element then continue to the ned of the list.
        curr = head;
        b = head;
        while (curr != nullptr) {
            n++;
            b = b -> next;
            if (n == k) {
                a = curr;
                b = head;
            }
            curr = curr -> next;
        }
                
        swap(a -> val, b -> val);
        
        return head;
    }
};