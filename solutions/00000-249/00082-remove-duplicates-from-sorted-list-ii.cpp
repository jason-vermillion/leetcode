// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
// 82. Remove Duplicates from Sorted List II
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
        ListNode* curr;
        ListNode* newHead;
        ListNode* newTail;
        map<int,int> freq;
        
        if (head == nullptr) return head;
        
        curr = head;
        while (curr != nullptr) {
            freq[curr -> val]++;
            curr = curr -> next;
        }
        
        for (auto x : freq) {
            if (x.second == 1) {
                if (newTail != nullptr) {
                    newTail -> next = new ListNode(x.first);
                    newTail = newTail -> next;
                }
                else {
                    newHead = new ListNode(x.first);
                    newTail = newHead;
                }
            }
        }
        
        return newHead;
    }
};