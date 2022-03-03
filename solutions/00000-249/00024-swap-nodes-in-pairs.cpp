// https://leetcode.com/problems/swap-nodes-in-pairs/
// Time complexity O(n)
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* newHead;
        ListNode* prev;
        ListNode* a;
        ListNode* b;
        ListNode* t;
        
        // empty or 1 node list.
        if (head == nullptr || head -> next == nullptr) {
            return head;
        }
        
        prev = nullptr;
        a = head;
        b = head -> next;
        newHead = b;
        while (a != nullptr && b != nullptr) {
            a -> next = b -> next;
            b -> next = a;
            if (prev != nullptr) {
                prev -> next = b;    
            }
            prev = a;
            a = a -> next;
            b = nullptr;
            if (a != nullptr && a -> next != nullptr) {
                b = a -> next;
            }
        }
        return newHead;
    }
};