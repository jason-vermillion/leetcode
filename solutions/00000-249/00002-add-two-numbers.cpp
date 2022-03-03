// https://leetcode.com/problems/add-two-numbers/
// 2. Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* out = nullptr;
        ListNode* tail = nullptr;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int carry = 0;
        
        while (p1 != nullptr || p2 != nullptr) {
            int a = 0;
            int b = 0;
            int val = 0;
            ListNode* curr;

            if (p1 != nullptr) {
                a = p1 -> val;
                p1 = p1 -> next;
            }

            if (p2 != nullptr) {
                b = p2 -> val;
                p2 = p2 -> next;
            }

            val = a + b + carry;
            carry = val / 10;
            val = val % 10;
            curr = new ListNode(val);
            
            if (out == nullptr) {
                out = curr;
                tail = curr;
            }
            else {
                tail -> next = curr;
                tail = curr;
            }            
        }
        
        if (carry > 0) {
            tail -> next = new ListNode(carry);
        }

        return out;
    }
};