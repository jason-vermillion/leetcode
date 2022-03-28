// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// 83. Remove Duplicates from Sorted List

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* prev;
        ListNode* curr;
        
        dummy -> next = head;
        prev = dummy;
        curr = head;
        
        while (curr != nullptr) {
            if (curr -> val == prev -> val) {
                prev -> next = curr -> next;
            }
            else {
                prev = curr;
            }
            curr = curr -> next;
        }
        
        return dummy -> next;
        
    }
};