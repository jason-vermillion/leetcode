// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// 19. Remove Nth Node From End of List

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        ListNode* newHead = nullptr;
        ListNode* nthNode = nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = nullptr;
        int i = 1;
        
        if (head == nullptr || (head -> next == nullptr && n == 1)) {
            return nullptr;
        }

        dummy -> next = head;
        prev = dummy;
        prev -> next = head;
        nthNode = head;

        // find the nthNode from the end
        curr = head;
        while (curr -> next != nullptr) {
            if (i >= n) {
                prev = prev -> next;
                nthNode = nthNode -> next;
            }

            i++;
            curr = curr -> next;
        }

        // delete the nthNode
        if (dummy -> next == nthNode) {
            dummy -> next = nthNode -> next;
        }
        prev -> next = nthNode -> next;

        newHead = dummy -> next;
        return newHead;
    }
};