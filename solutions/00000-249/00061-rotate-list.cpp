// https://leetcode.com/problems/rotate-list/
// 61. Rotate List
// time complexity O(n)
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
    ListNode* rotateRight(ListNode* head, int k) {
        int n;
        ListNode* curr;
        ListNode* prev;
        ListNode* dummy;
        ListNode* newHead;
        ListNode* tail;
        
        if (head == nullptr || head -> next == nullptr) {
            return head;
        }
        
        dummy = new ListNode(INT_MIN);
        dummy -> next = head;
        
        // count the number of nodes in the list
        curr = head;
        n = 0;
        while (curr != nullptr) {
            n++;
            tail = curr;
            curr = curr -> next;
        }
        
        // find the new head and tail.
        k = k % n;
        if (k == 0) {
            return head;
        }
        
        int start = (n - k) % n;
        prev = dummy;
        newHead = head;
        for (int i = 0; i < start; ++i) {
            newHead = newHead -> next;
            prev = prev -> next;
        }
        
        prev -> next = nullptr;
        tail -> next = head;
        return newHead;
    }
};