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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        ListNode* next;
        ListNode* c1 = list1;
        ListNode* c2 = list2;
        
        
        while(c1 || c2 ) {
            if (c1 && c2 ) {
                next = new ListNode();
                next -> next = NULL;
                if (c1 -> val <= c2 -> val) {
                    next -> val = c1 -> val;
                    c1 = c1 -> next;
                }
                else {
                    next -> val = c2 -> val;
                    c2 = c2 -> next;
                }
            }
            else if (c1) {
                next = new ListNode(c1 -> val);
                next -> next = NULL;
                c1 = c1 -> next;
            }
            else if (c2) {
                next = new ListNode(c2 -> val);
                next -> next = NULL;
                c2 = c2 -> next;
            }
            
            if (head == NULL) {
                head = next;
                tail = next;
            }
            else {
                tail -> next = next;
                tail = next;
            }
        }
    
        
        return head;
    }
    
    void printList(ListNode* head) {
        ListNode* x = head;
        while(x) {
            cout << x -> val << " ";
            x = x -> next;
        }
        cout << endl;    
    }
};